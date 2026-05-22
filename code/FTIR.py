import numpy as np
from _apodizer import Apodizer as ap
from scipy.interpolate import interp1d

LASER_WAVENUMBER = 7630
HE_NE_LAMBDA = 1e-2/LASER_WAVENUMBER # meters
N_AIR = 1.00027

def interpol(low_res, full_len):
    x_old = np.linspace(0, 1, len(low_res))
    x_new = np.linspace(0, 1, full_len)
    return interp1d(x_old, low_res, kind='linear', fill_value="extrapolate")(x_new)

def get_wavenumbers(n_points):
    """
    n_points: Number of points in the real spectrum (half of FFT result)
    total_points: Total points used in the FFT (including zero padding)
    """
    # Sampling frequency in cm^-1
    delta_opd = (HE_NE_LAMBDA / N_AIR) / 2.0
    fs = 1.0 / (delta_opd * 100) 
    waves = np.linspace(0, fs / 2, n_points)
    return waves

def phase_corrected(spectra, phase):
    return spectra * np.exp(-1j * phase)

def pipramp(interferogram):
    zpd = np.argmax(np.abs(interferogram))
    double_sided_len = zpd * 2
    ramp = np.ones(len(interferogram))
    # Linear ramp for the double-sided portion to handle the ZPD offset
    ramp[:double_sided_len] = np.linspace(0, 1, double_sided_len)
    return interferogram * ramp

def truncate_to_resolution(clocked_ir, target_res=4.0):
    delta_opd = (HE_NE_LAMBDA / N_AIR) / 2
    required_total_opd = 1.0 / target_res
    num_points_needed = int(required_total_opd / delta_opd)
    zpd_idx = np.argmax(np.abs(clocked_ir))
    return clocked_ir[:zpd_idx + num_points_needed]

def to_mean(lst):
    return lst - sum(lst)/len(lst)

def symmetrize(lst, points = 512):
    idx = np.argmax(np.abs(lst))
    half = points//2
    start = idx - half
    end = idx + half

    # Handle boundaries safely
    if start < 0:
        start = 0
        end = points
    elif end > len(lst):
        end = len(lst)
        start = end - points

    centered_512 = lst[start:end]
    return centered_512

def rotate(meaned):
    idx = np.argmax(np.abs(meaned))
    rotated = np.roll(meaned, -idx)
    return rotated

def zero_fill(lst, pad_factor=2):
    if(pad_factor==0):
        return len(lst)
    return 2**int(np.ceil(np.log2(len(lst) * pad_factor)))

def apodize(ifg, method = 'hamming', about = 'zpd'):
    apodizer = ap(method)
    return apodizer.apodize(ifg, about = about)

def phase_angle(fft):
    return np.unwrap(np.angle(fft))



