import lzma
with open("dict.txt") as f:
	data = f.read().encode().split(b"\n")
out = [data[0]]
for i in range(1, len(data)):
    s1, s2 = data[i - 1], data[i]
    pl = 0
    mi = min(len(s1), len(s2))
    while pl < mi and s1[pl] == s2[pl]:
        pl += 1
    if pl >= 1:
        out.append(bytes([255, 11 + pl]) + s2[pl : ])
    else:
    	out.append(s2)
enc = lzma.compress(b"\n".join(out[ : 75751]))
with open("bin.txt", "wb") as f:
	f.write(enc)