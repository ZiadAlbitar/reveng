from collections import deque

import numpy as np
from matplotlib import pyplot as plt
import scienceplots 

from scipy.signal import savgol_filter
import pandas as pd

# Assuming these are available in your local environment
from confsmooth import confsmooth
from data import get_data, resample
from FTIR import *


def get_phase_map(data):
    centered = symmetrize(data, 512)
    rotated = rotate(centered)
    fft_phase = np.fft.fft(rotated)
    phase = phase_angle(fft_phase)

    return phase

def get_fourier_transform(ref_laser, interferogram, zero_fill_factor = 1, window = 'hamming', spectral_resolution = 4.0):
    clocked_ir = resample(interferogram, ref_laser)

    meaned_interferogram = to_mean(clocked_ir)
    apodized = apodize(meaned_interferogram, window, about = 'zpd')

    pip = pipramp(apodized)
    phase_map = get_phase_map(pip)


    z_len = zero_fill(apodized, zero_fill_factor) # Usually doubles the length
    padded = np.pad(pip, (0, z_len - len(pip)), mode='constant')

    rot = rotate(padded)
    fft_full = np.fft.fft(rot)

    # ---------- Phase correction ----------
    phase_interp = interpol(phase_map, z_len)
    corrected = phase_corrected(fft_full, phase_interp)

    h = len(corrected) // 2
    waves = get_wavenumbers(h)

    return waves, corrected[:h].real

def calc_absorbance(background, sample, waves):
    bg_clean = np.maximum(background, 1e-6) # Avoid division by zero
    sample_clean = np.maximum(sample, 1e-6)

    # Thresholding to find the useful spectral range
    threshold = 0.02 * np.max(bg_clean)
    mask = bg_clean > threshold

    # Calculate Absorbance ONLY within the mask to avoid the "zero-line"
    transmittance = sample_clean[mask] / bg_clean[mask]
    absorbance = -np.log10(transmittance)
    waves_final = waves[mask]

    # ---------- Smoothing ----------
    # Window length must be odd
    A_smoothed = savgol_filter(absorbance, window_length=11, polyorder=2)

    return A_smoothed, waves_final

def get_intensity_spectrum(queue: deque, scans: int):
    for i in range(scans):
        test = queue.index(i)  
    
    return

def plot_raw_measurement(data):
    return

if __name__ == "__main__":
    PATH = "outputs/iso_prop_2.csv"

    # Load data
    bg_laser, bg_ir = get_data(85679, num_packets= 458, PATH = PATH)
    sample_laser, sample_ir = get_data(200531, num_packets= 458, PATH = PATH)

    waves_bg, background = get_fourier_transform(bg_laser, bg_ir)
    waves_sm, sample = get_fourier_transform(sample_laser, sample_ir)

    absorbance, waves = calc_absorbance(background, sample, waves_sm)

    # ---------- Reference ----------
    try:
        df = pd.read_csv("reference/iso_propanol_reference.csv", sep=";", decimal=",")
    except FileNotFoundError:
        print("Reference file not found, skipping reference plot.")
        df = None

    
    # ---------- Plot ----------
    plt.style.use('.\\scienceplots\\science.mplstyle')

    plt.figure(figsize=(10, 6))
    plt.plot(resample(sample_ir, sample_laser))
    plt.xlabel(r"Mirror position (mm)")
    plt.ylabel(r"Intensity")
    plt.title(r"Interferogram of Isopropanol")
    plt.xlim(0, 1300)


    plt.figure(figsize=(10, 6))
    plt.plot(waves, absorbance, linewidth=1.0, label=r"Raw Estimation", alpha=0.8)

    if df is not None:
        plt.plot(df["Wavenumber"], df["Intensity"],
                linewidth=1, label=r"Reference", alpha=0.7)

    plt.legend()
    plt.ylim(-0.05, 0.6)
    plt.xlim(4000, 650)

    plt.xlabel(r"Wavenumber ($\mathrm{cm}^{-1}$)")
    plt.ylabel(r"Absorbance")
    plt.title(r"Phase-corrected Isopropanol spectrum")

    plt.grid(True, which='both', linestyle='--', alpha=0.5)

    plt.show()