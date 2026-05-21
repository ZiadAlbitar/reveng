import usb.core
import usb.util

# Find all devices
devices = usb.core.find(find_all=True)

for dev in devices:
    print(f"Device: {dev.idVendor:04x}:{dev.idProduct:04x}")
# import usb.core

# import usb.util

# # find our device
# dev = usb.core.find(idVendor=0x0fb4, idProduct=0x0201)

# # was it found?
# if dev is None:
#     raise ValueError('Device not found')

# # set the active configuration. With no arguments, the first
# # configuration will be the active one
# dev.set_configuration()

# # get an endpoint instance
# cfg = dev.get_active_configuration()
# intf = cfg[(0,0)]

# ep = usb.util.find_descriptor(
#     intf,
#     # match the first OUT endpoint
#     custom_match = \
#     lambda e: \
#         usb.util.endpoint_direction(e.bEndpointAddress) == \
#         usb.util.ENDPOINT_OUT)

# assert ep is not None

# # write the data
# ep.write('test')