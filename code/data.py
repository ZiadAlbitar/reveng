import numpy as np
from scipy.interpolate import interp1d
from numpy.typing import NDArray
import csv
import matplotlib.pyplot as plt
from scipy.interpolate import interp1d

# --- 1. PARSING UTILITIES ---


def parse_24bit_signed(b1: int, b2: int, b3: int) -> int:
    """
    parses a 3 byte number to a two's compliment number

    Parameters
    ----------
    b1: 1 byte integer
        most significant byte

    b2: 1 byte integer
        middle byte

    b3: 1 byte integer
        least significant byte

    Returns
    ----------
    val: integer
        two's compliment 3 byte integer
    """
    val = (b1 << 16) | (b2 << 8) | b3

    if val & 0x800000:
        val -= 0x1000000

    return val

def scale_plot(interferogram: NDArray[np.float64], scale_factor: int = 256) -> NDArray[np.float64]:
    """
    scales interferogram to match peaks with real values

    Parameters
    ----------
    interferogram: NDArray
        numpy array of interferogram
    scale_factor: positive integer, optional 
        factor of which to scale interferogram, default 256

    Returns
    ----------
    scaled_interferogram: NDArray
        Scaled interferogram
    """
    
    if(scale_factor <= 0):
        scale_factor = 256
    return interferogram/scale_factor

def read_csv(csv_file, start_row, num_packets):
    ir_stream = []
    laser_stream = []
    
    with open(csv_file, "r") as f:
        reader = csv.reader(f)
        data_rows = list(reader)
        
    measurement_range = data_rows[start_row-1  : start_row - 1   + num_packets]

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

def get_streams(data_rows):
    ir_stream = []
    laser_stream = []

    for byte in data_rows[1:]:
        if len(byte) < 7: continue
        
        for i in range(0, len(byte), 8):
            if i + 8 > len(byte): break
            
            # Even ID (Slot 1) -> IR Interferogram
            ir_val = parse_24bit_signed(byte[i+1], byte[i+2], byte[i+3])
            ir_stream.append(ir_val)
            
            # Odd ID (Slot 2) -> Laser Reference
            laser_val = parse_24bit_signed(byte[i+5], byte[i+6], byte[i+7])
            laser_stream.append(laser_val)
                
    return np.array(ir_stream), np.array(laser_stream)

# --- 2. STEP 2: FRINGE MAPPING (RE-GRIDDING) ---

def resample(ir_data: NDArray[np.float64], laser_data: NDArray[np.float64]) -> NDArray[np.float64]:
    """
    Samples IR-data at every zero crossing from laser data.

    returns clocked ir data.
    
    Parameters
    ----------
    ir_data : ndarray of integers
        Array containing ir data captured from spectrometer
    laser_data : ndarray of integers
        reference laser data captured by spectrometer

    Returns
    -------
    clocked_ir : ndarray
        Interferogram resulted from sampling ir data at every zero crossing of reference laser data.
    """

    # Remove DC offset from laser
    laser_centered = laser_data - np.mean(laser_data)

    # Find zero crossings
    sign_changes = np.where(np.diff(np.sign(laser_centered)))[0]

    zero_crossings = []
    directions = []

    for idx in sign_changes:
        y0, y1 = laser_centered[idx], laser_centered[idx + 1]

        # sub-sample crossing
        frac_idx = idx + (0 - y0) / (y1 - y0)
        zero_crossings.append(frac_idx)

        # +1 = upward, -1 = downward
        directions.append(np.sign(y1 - y0))

    zero_crossings = np.array(zero_crossings)
    directions = np.array(directions)

    # Keep only valid (non-zero) directions
    valid = directions != 0
    zero_crossings = zero_crossings[valid]
    directions = directions[valid]

    # Find first upward crossing
    first_up = np.where(directions > 0)[0][0]

    # Shift so we start at a consistent phase
    zero_crossings = zero_crossings[first_up:]

    # Interpolate IR data onto crossing points
    ir_interp_func = interp1d(
        np.arange(len(ir_data)),
        ir_data,
        kind='linear',
        fill_value="extrapolate"
    )

    clocked_ir = ir_interp_func(zero_crossings)

    return clocked_ir

def get_data(start, num_packets = 458, PATH = "outputs/started_1_2_out.csv"):    
    print("Extracting streams...")
    ir_raw, laser_raw = get_streams(PATH, start, num_packets)

    return laser_raw, scale_plot(ir_raw, scale_factor=256)

# --- MAIN EXECUTION ---

if __name__ == "__main__":
    PATH = "outputs/started_1_2_out.csv"
    
    print("Extracting streams...")
    ir_raw, laser_raw = get_streams(PATH, 4604, 458)
    
    print("Performing Fringe Mapping (Step 2)...")
    clocked_ir = resample(ir_raw, laser_raw)
    
    print("Processing Mertz Method...")
    
    # Plotting
    plt.plot(clocked_ir, color='blue', linewidth=0.5)
    plt.title("Clocked Interferogram (Step 2)")
    plt.xlabel("Mirror Position (Fringes)")
    
    plt.show()