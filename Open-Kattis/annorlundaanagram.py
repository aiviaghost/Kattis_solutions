from collections import defaultdict

s = "".join(sorted(input()))
n = len(s)

count = defaultdict(lambda: 0)

if all(c == s[0] for c in s):
    print(-1)
    exit(0)

for c in s:
    count[c] += 1

mc, freq = max(list(count.items()), key=lambda x: x[1])

if freq >= n // 2:
    start = s.find(mc)
    p0 = s[ : start]
    p1 = s[start : start + n // 2]
    p2 = s[start + n // 2 : start + freq]
    p4 = s[start + freq :]
    s = "".join([p1, p0, p4, p2])

print(s)
