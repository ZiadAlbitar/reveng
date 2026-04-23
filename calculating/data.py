import csv
import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import interp1d

# --- 1. PARSING UTILITIES ---

def parse_24bit_signed(b1, b2, b3):
    val = (b1 << 16) | (b2 << 8) | b3
    if val & 0x800000:
        val -= 0x1000000
    return val / 256

def get_streams(csv_file, start_row, num_packets):
    ir_stream = []
    laser_stream = []
    
    with open(csv_file, "r") as f:
        reader = csv.reader(f)
        data_rows = list(reader)

    measurement_range = data_rows[start_row-1  : start_row-1  + num_packets]

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

# --- 2. STEP 2: FRINGE MAPPING (RE-GRIDDING) ---

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

def get_data(PATH = "outputs/started_1_2_out.csv"):    
    print("Extracting streams...")
    ir_raw, laser_raw = get_streams(PATH, 4604, 458)
    
    print("Performing Fringe Mapping (Step 2)...")
    clocked_ir = fringe_map(ir_raw, laser_raw)
    return clocked_ir, ir_raw, laser_raw

# --- MAIN EXECUTION ---

if __name__ == "__main__":
    PATH = "outputs/started_1_2_out.csv"
    
    print("Extracting streams...")
    ir_raw, laser_raw = get_streams(PATH, 4604, 458)
    
    print("Performing Fringe Mapping (Step 2)...")
    clocked_ir = fringe_map(ir_raw, laser_raw)
    
    print("Processing Mertz Method...")
    
    # Plotting
    plt.plot(clocked_ir, color='blue', linewidth=0.5)
    plt.title("Clocked Interferogram (Step 2)")
    plt.xlabel("Mirror Position (Fringes)")
    
    plt.show()