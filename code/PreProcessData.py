a = "0d00000407ff0001000000000000000000000000000000000018a2a40000000000000000000000000018a2a40000000000001f88000000000000000000000000"
"""
cmd_copy(self, frame_type: int, pipe_id: int, command: int, 
                 flags: int, param0: int=0, param1: int=0, payload="")"""

def format_cmd_copy_call(data):
    print(data[0:2])
    frame_type = data[0:2]
    pipe_id = data[6:8]
    command = data[8:10]
    flags = data[14:16]
    param0 = data[16:24]
    param1 = data[24:32]
    payload = data[32:]
    
    return f"cmd_copy(0x{frame_type}, 0x{pipe_id}, 0x{flags}, 0x{param0}, 0x{param1}, 0x{payload})\n"

def pre_process_capture_data(input_file, output_file):
    with open(input_file, "r", encoding="utf-8") as infile, \
         open(output_file, "w", encoding="utf-8") as outfile:

        for line in infile:
            if "Leftover Capture Data:" in line:
                # Split and extract the data after the colon
                data = line.split("Leftover Capture Data:")[1].strip()
                data = format_cmd_copy_call(data)
                outfile.write(data)


# Example usage
pre_process_capture_data("newsniffbulkin.txt", "proccessedbulkin.txt")

#print(format_cmd_copy_call(a))

