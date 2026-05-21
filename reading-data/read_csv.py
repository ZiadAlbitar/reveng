import csv
from test import parse_hex_stream  # or paste function above


def process_csv(csv_file):
    all_parsed = []

    with open(csv_file, "r") as f:
        reader = csv.reader(f)

        for row in reader:
            if len(row) < 7:
                continue

            frame_no = row[0]
            time_rel = row[1]
            length = row[2]
            protocols = row[3]
            src = row[4]
            dst = row[5]
            hex_data = row[6]

            # skip empty payloads
            if not hex_data:
                continue

            parsed = parse_hex_stream(hex_data, skip_first_byte=False)

            all_parsed.append({
                "frame": frame_no,
                "time": time_rel,
                "len": length,
                "src": src,
                "dst": dst,
                "values": parsed
            })

    return all_parsed


if __name__ == "__main__":
    data = process_csv("outputs/started_1_2_out.csv")
    i = 4604
    ids = set()
    values = set()
    pairs = {}
    id_count = {}
    id_count1 = {}
    count_equal = 0
    count_diff = 0
    n = 0
    for packet in data[i-1:i-1+1]:
        print(packet["frame"], packet["time"])
        for r in packet["values"]:
            id1 = r["ID1"]
            id2 = r["ID2"]
            if r["ID2"] == r["ID1"] + 1:
                count_equal += 1
                print(r)
                val = r["Value1"]
                ids.add(r["ID1"])
                values.add(r["Value1"])
                val = r["Value1"]


                if id1 not in id_count:
                    id_count[id1] = 0
                id_count[id1] += 1

            else:
                if id1 not in id_count1:
                    id_count1[id1] = 0
                id_count1[id1] += 1
                if id1 not in pairs:
                    pairs[id1] = []
                pairs[id1].append(id2)
                count_diff += 1
    # print(sorted(ids))
    # print(len(ids))
    # #print(id_count)
    # #print((values))
    # print(len(values))   
    # print(pairs)
    # print(count_diff)
    # print(count_equal)
    # sorted_list = sorted(id_count.items(), key=lambda x: x[1], reverse=True)
    # print(sorted_list)
    # sorted_list1 = sorted(id_count1.items(), key=lambda x: x[1], reverse=True)
    # print(sorted_list1)

    #512/8

    #output.csv measurment_sniff
    #[0, 8, 16, 24, 32, 48, 56, 64, 80, 88, 96, 112, 120, 128, 136, 144, 152, 160, 168, 176, 184, 192, 208, 224, 240, 248]

    #output2.csv 1sniff
    #[0, 8, 16, 24, 32, 48, 64, 72, 80, 88, 96, 104, 112, 120, 128, 136, 144, 152, 160, 168, 176, 184, 192, 200, 208, 224, 240, 248]