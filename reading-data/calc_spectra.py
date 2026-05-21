import csv
import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import interp1d
from scipy.fft import fft

wavelen = 632.8e-9

def parse_24bit_signed(b1, b2, b3):
    val = (b1 << 16) | (b2 << 8) | b3
    if val & 0x800000:
        val -= 0x1000000
    return val/256

def get_data(csv_file, start_row, num_packets):
    ir_stream = []
    laser_stream = []
    
    with open(csv_file, "r") as f:
        reader = csv.reader(f)
        data_rows = list(reader)

    measurement_range = data_rows[start_row -1 : start_row -1 + num_packets]

    for row in measurement_range:
        if len(row) < 7: continue
        payload = bytes.fromhex(row[6])[8:] # Skip 8-byte USB header
        
        for i in range(0, len(payload), 8):
            if i + 8 > len(payload): break
            
            # Even ID (Slot 1) -> IR Interferogram
            ir_val = parse_24bit_signed(payload[i+1], payload[i+2], payload[i+3])
            ir_stream.append(ir_val)
            
            # Odd ID (Slot 2) -> Laser Reference
            laser_val = parse_24bit_signed(payload[i+5], payload[i+6], payload[i+7])
            laser_stream.append(laser_val)
                
    return np.array(ir_stream), np.array(laser_stream)


def fringe_map(ir_data, laser_data):
    # Remove DC offset from laser
    laser_centered = laser_data - np.mean(laser_data)
    
    # Find zero crossings
    sign_changes = np.where(np.diff(np.sign(laser_centered)))[0]
    
    zero_crossings = []
    for idx in sign_changes:
        y0, y1 = laser_centered[idx], laser_centered[idx+1]
        # Linear interpolation for sub-sample precision
        fractional_idx = idx + (0 - y0) / (y1 - y0)
        zero_crossings.append(fractional_idx)
    
    # Interpolate IR data onto these crossing points
    ir_interp_func = interp1d(np.arange(len(ir_data)), ir_data, kind='linear', fill_value="extrapolate")
    clocked_ir = ir_interp_func(zero_crossings)
    
    return clocked_ir

def apodization(rotated_data):
    #window = np.hamming(len(rotated_data))
    #window = np.bartlett(len(rotated_data))
    x = np.linspace(-1, 1, len(rotated_data))

    # Happ–Genzel window
    window = 0.54 + 0.46 * np.cos(np.pi * x)
    return rotated_data * window

# --- MAIN EXECUTION ---

if __name__ == "__main__":
    PATH = "outputs/started_1_2_out.csv"
    
    print("Extracting streams...")
    ir_raw, laser_raw = get_data(PATH, 4604, 458)
    
    print("Performing Fringe Mapping (Step 2)...")
    clocked_ir = fringe_map(ir_raw, laser_raw)
    
    print("Processing Mertz Method...")

    print(max(clocked_ir, key=abs))
    #idx = clocked_ir.index(max(clocked_ir))  # index of max element

    clocked_ir = clocked_ir - np.mean(clocked_ir)
    idx = np.argmax(np.abs(clocked_ir))


    # 3. Extract 512-point window centered at ZPD
    half = 256
    start = idx - half
    end = idx + half

    # Handle boundaries safely
    if start < 0:
        start = 0
        end = 512
    elif end > len(clocked_ir):
        end = len(clocked_ir)
        start = end - 512

    centered_512 = clocked_ir[start:end]

    # 4. Apply triangular window
    final = apodization(centered_512)

    # --- 2. APODIZE FIRST ---
    # Force the edges of the measurement to zero
    clocked_ir = apodization(clocked_ir)

    # --- 3. FIND ZPD AND ROTATE ---
    idx = np.argmax(np.abs(clocked_ir))
    rotated = np.roll(clocked_ir, -idx)
    #rotated = clocked_ir[idx:] + clocked_ir[:idx]

    idx = np.argmax(np.abs(final))
    rotated=np.roll(final,-idx)

    n_fft = 2**int(np.ceil(np.log2(len(rotated))) )

    # 2. Perform the FFT
    # Use rfft (Real FFT) for efficiency with real-valued data
    fft_data = np.fft.rfft(rotated, n=n_fft)

    # 3. Calculate Magnitude (Power Spectrum)
    # We take the absolute value to get the intensity
    magnitude = np.abs(fft_data)

    # 4. Generate the Wavenumber Axis (cm-1)
    # Step size in cm is (Wavelength in nm * 1e-7) / 4
    step_cm = (632.8 * 1e-7) / 4 
    max_nu = 1 / (2 * step_cm)
    wavenumbers = np.linspace(0, max_nu, len(magnitude))
    
    # Plotting
    plt.figure(figsize=(12, 6))

    plt.subplot(1, 3, 1)
    plt.plot(clocked_ir, color='blue', linewidth=0.5)
    plt.title("Clocked Interferogram (Step 2)")
    plt.xlabel("Mirror Position (Fringes)")
    
    plt.subplot(1, 3, 2)
    plt.plot(rotated, color='blue', linewidth=0.5)
    plt.title("Clocked Interferogram (Step 2)")
    plt.xlabel("Mirror Position (Fringes)")

    plt.subplot(1,3,3)
    plt.plot(wavenumbers, magnitude, color='red', linewidth=0.8)
    plt.title("Fourier Transform (Raw Spectrum)")
    plt.xlabel("Wavenumber (cm⁻¹)")
    plt.ylabel("Intensity")
    plt.xlim(400, 10000) # Most interesting Mid-IR range
    plt.grid(True, alpha=0.3)

    plt.show()
