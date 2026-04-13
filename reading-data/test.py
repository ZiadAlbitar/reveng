# Sample Python code to parse FTIR-like hex data

import struct

def parse_hex_stream(hex_string, skip_first_byte=True):
    """
    Parse a hex string into 8-byte records: [ID:2][Index:2][Value:4].
    Args:
        hex_string (str): A string with hex bytes, e.g., "c0 00 0a b5 c1 e6 a0 a4 18 ..."
        skip_first_byte (bool): True if the first byte is not part of the records
    Returns:
        List of dicts: [{'ID': int, 'Index': int, 'Value': int}, ...]
    """
    # Remove whitespace and split into bytes
    hex_bytes = bytes.fromhex(''.join(hex_string.split()))
    
    # Optionally skip the first byte
    if skip_first_byte:
        hex_bytes = hex_bytes[1:]
    
    records = []
    record_size = 8
    
    for i in range(0, len(hex_bytes) - record_size + 1, record_size):
        chunk = hex_bytes[i:i+record_size]
        
        # Unpack little-endian: ID=uint16, Index=uint16, Value=uint32
        ID, Index, Value = struct.unpack('<HHI', chunk)
        records.append({
            'ID': ID,
            'Index': Index,
            'Value': Value
        })
    
    return records


# Example usage:
hex_data = """
18ffff6079e3609388fffec4c9e77708c0fffe45c1f266a7c0fffdf4c1012310c0fffd79c10f93e1c0fffd0d1919b30e78fffc91891cb48ce8fffc19e117c21be0fffc1de10c373ce0fffbcee1fd47c2e0fffbd4e1ef201de0fffc0ee1e5b47e18fffb9c79e39ce588fffb60c9e96df8c0fffbccc1f58dd1c0fffc10c1049a4ec0fffc6bc11263cdc0fffd56191b137a78fffddf891c43f0a8fffee8a1159d45a0ffffe1a108f61da000007ba1f9d3aca000014ca1ec6dc1a00001a3a1e483ac180001f679e444c1880002ca99ebbfc8900002c891f8e2ca90000381910805ff900004749114f25c18000435791c0f1f8800049fa91b6686a000054ca11322eea000066da1058e8aa00006f0a1f6718ca00007b2a1ea0568a000087f19e3be477800091989e558eab8000974b1ee62c2b00009e1b1fc5800b0000a2eb10b585cb0000a75b117330318000a32791ca06b88000a54b91a1e99b0000a94b1105ce9b0000a7bb1020ec0b000095db1f3334eb0000931b1e7eef8b00008b119e364a77800085389e6d379a80007e3a1f148d2a000079da1ffdbaba00006d4a10e7db5a000071919191a797800071e891cc3e4b80006b7b1187363b00006afb10d5869b00006c5b1fe890cb000064ab1f0278fb000059bb1e637f31800054f79e37a3d880004e0b9e8b05ab0000452b1f468f3b00003b3b10360c2b000038db1116d48
"""
parsed = parse_hex_stream(hex_data)

# Print results
for rec in parsed:
    print(f"ID: {rec['ID']:04X}, Index: {rec['Index']:04X}, Value: {rec['Value'] * 2**-32}")

