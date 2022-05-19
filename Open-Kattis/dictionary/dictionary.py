import lzma
with open("/src/bin.txt", "rb") as f:
	data = lzma.decompress(f.read()).split(b"\n")
c = 255
cc = bytes([c])
out = [data[0]]
for i in range(1, len(data)):
    if data[i][0] == c:
        rep = data[i][1] - 11
        out.append(out[-1][ : rep] + data[i][2 : ])
    else:
    	out.append(data[i])
print("\n".join(map(bytes.decode, out)))