n = int(input())

s = input()
idxs = list(range(n))

mirko = []
slavko = []

sorted_seq = sorted([(c, -i) for i, c in enumerate(s)], reverse=True)

seen = set()
even = True
for _ in range(n):
    if even:
        idx = idxs.pop()
        while idx in seen:
            idx = idxs.pop()
        seen.add(idx)
        mirko.append(s[idx])
    else:
        c, pos = sorted_seq.pop()
        while -pos in seen:
            c, pos = sorted_seq.pop()
        seen.add(-pos)
        slavko.append(c)
    even = not even

print("DA" if slavko < mirko else "NE")
print("".join(slavko))
