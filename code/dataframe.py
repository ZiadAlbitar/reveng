import argparse
from dataclasses import dataclass
from typing import Optional

# Fields that construct the header of the CaryFTIRs packets
@dataclass
class Frame:
    type: int
    sequence: int
    pipe_id: int
    command: int 
    status: int
    payload_len: int
    flags: int
    param0: int
    param1: int
    payload: bytes

    def __str__(self) -> str:
        return (
            f"Frame(type=0x{self.type:02x}, seq={self.sequence}, pipe=0x{self.pipe_id:02x}, "
            f"cmd=0x{self.command:02x}, status=0x{self.status:02x}, flags=0x{self.flags:02x}, "
            f"len={self.payload_len}, param0=0x{self.param0:08x}, param1=0x{self.param1:08x})"
            f"\npaylod={self.payload.hex(' ')}"
        )

def one_to_four(x):
    x = int(x)
    if x < 1 or x > 4:
        raise argparse.ArgumentTypeError("--bg and --sample must be between 1 and 4")
    return x
# Settings for the CaryFTIR spectrometer run
# Can be specified or left to their default values
@dataclass
class Settings:
    output: Optional[str] = None 
    plot_output: Optional[str] = None
    start_cm: float = 4000
    stop_cm: float = 650.0
    resolution: int = 4
    vendor_id: int = 4020
    product_id: int = 513
    data_seconds: float = 10.0
    max_data_frames: int = 500
    pre_measure_polls: int = 16
    poll_delay: float = 0.109
    plot_enabled: bool = True
    show_plot: bool = True
    bg_scans: one_to_four = 3
    sample_scans: one_to_four = 3