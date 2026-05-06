create csv by running this command but instead of YOUR_SNIFF the name of the pcapng file and instead of OUT what you want the csv file to be called

change device_address to the correct address. The lenghts chosen here are for parsing measurements

tshark -r YOUR_SNIFF.pcapng -Y "usb.device_address == 20 && (frame.len == 111 || frame.len == 103 || frame.len == 105 || frame.len == 539)" -T fields -E separator=, -e frame.number -e frame.time_relative -e frame.len -e frame.protocols -e usb.src -e usb.dst -e usb.capdata > OUT.csv