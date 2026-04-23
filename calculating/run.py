from data import get_data
from matplotlib import pyplot as plt
import numpy as np
from FTIR import *
from scipy.interpolate import interp1d

def get_wavenumbers(num_points, lambda_hene_nm=632.8):
    # 1. Delta OPD in cm
    delta_opd = (lambda_hene_nm * 1e-7) / 2
    
    # 2. Nyquist Frequency (cm^-1)
    nyquist = 1 / (2 * delta_opd)
    
    # 3. Create the wavenumber axis for the first half of the FFT
    # num_points here should be the length of your FFT (e.g., 512)
    wavenumbers = np.linspace(0, nyquist, num_points)
    
    return wavenumbers

def phase_corrected(spectra, phase):
    """
    Applies Mertz phase correction.
    spectra: The complex FFT result of the full interferogram.
    phase: The interpolated phase map from the short scan.
    """
    # Standard Mertz rotation: multiply by exp(-i * phase)
    # This 'unwinds' the phase error
    corrected_complex = spectra * np.exp(-1j * phase)
    
    # 2. Return the Real component
    return corrected_complex

def interpol(low_res, full_len):
    x_old = np.linspace(0, 1, len(low_res))
    
    # 3. Create the new x-axis (normalized 0 to 1)
    x_new = np.linspace(0, 1, full_len)
    
    # 4. Define the interpolation function (linear is standard for Mertz)
    interpolator = interp1d(x_old, low_res, kind='linear', fill_value="extrapolate")
    
    # 5. Generate the stretched phase map
    high_res_phase = interpolator(x_new)
    
    return high_res_phase

def pipramp(interferogram):
    """
    Applies a Mertz ramp to handle the transition from 
    double-sided to single-sided data.
    """
    # Use argmax(abs) to safely find ZPD regardless of polarity
    zpd = np.argmax(np.abs(interferogram)) 
    
    # The double-sided region is 2 * zpd (from 0 to the mirror image of the left wing)
    double_sided_len = zpd * 2
    
    # Create the ramp: 0 at start, 1 at the end of the double-sided region
    ramp_segment = np.linspace(0, 1, double_sided_len)
    
    # Create a full-length array of 1s
    full_ramp = np.ones(len(interferogram))
    
    # Overlay the ramp onto the beginning
    # (If the interferogram is shorter than the segment, truncate the segment)
    limit = min(len(full_ramp), double_sided_len)
    full_ramp[:limit] = ramp_segment[:limit]
    
    return interferogram * full_ramp



if __name__ == "__main__":
    PATH = "outputs/started_1_2_out.csv"
    clocked_ir, _, __ = get_data(PATH)

    meaned = to_mean(clocked_ir)

    # pip ramp here
    pip = pipramp(meaned)

    centered = symmetrize(pip, 512)
    apodized = apodize(centered, 'hamming', about="zpd")

    rotated = rotate(apodized)

    zero_fill_factor = zero_fill(rotated)


    idk = np.fft.fft(rotated)
    half_point = len(idk) // 2
    final = np.abs(idk)

    phase = phase_angle(idk)

    wavenumbers = get_wavenumbers(512, 632.8)

    corrected = phase_corrected(idk, phase)


    # ____________________full interferogram________________________#
    mean = to_mean(clocked_ir)
    pip2 = pipramp(mean)
    apo = apodize(pip2, 'hamming', about='zpd')
    z = zero_fill(apo, 2)
    padded = np.pad(apo, (0, z - len(apo)), mode='constant')
    rot = rotate(padded)
    f = np.fft.fft(rot)
    h = len(f) // 2
    print(z)
    print(len(f))

    interpolated = interpol(phase, z)
    corr = phase_corrected(f,interpolated)

    waves = get_wavenumbers(len(f)//2)

    # plt.figure()
    # plt.plot(wavenumbers, -idk.real, linewidth=0.5)
    # plt.title("fft'd")
    # plt.figure()
    # plt.plot(wavenumbers, idk.imag, linewidth=0.5)
    # plt.title("fft'd")


    # plt.figure()
    # plt.plot(wavenumbers, phase, linewidth=0.5)
    # plt.title("phase")

    # plt.figure()
    # plt.plot(wavenumbers, corrected, linewidth=0.5)
    # plt.title("corrected")

    plt.figure()
    plt.plot(waves, interpolated[:h], linewidth=0.5)
    plt.title("interpolated phase")

    plt.figure()
    plt.plot(waves, -f[:h].real, linewidth=0.5)
    plt.xlim(400, 4000) # Standard IR view
    plt.title("real")

    plt.figure()
    plt.plot(waves, corr[:h].real, linewidth=0.5)
    plt.xlim(400, 4000) # Standard IR view
    plt.title("corrected")

    plt.show()
