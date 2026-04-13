from dataclasses import dataclass

@dataclass
class Frame:
    type: int
    sequence: int
    pipe_id: int # Unsure
    command: int 
    status: int
    payload_len: int # Seems to be true for some
    flags: int # Unsure
    param0: int # Unsure
    param1: int # Unsure
    payload: bytes

    def __str__(self) -> str:
        return (
            f"Frame(type=0x{self.type:02x}, seq={self.sequence}, pipe=0x{self.pipe_id:02x}, "
            f"cmd=0x{self.command:02x}, status=0x{self.status:02x}, flags=0x{self.flags:02x}, "
            f"len={self.payload_len}, param0=0x{self.param0:08x}, param1=0x{self.param1:08x})"
        )

@dataclass
class MeasurementFrame:
    pass
