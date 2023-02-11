n, l, p = map(int, input().split())

tp = []
for i in range(n):
    tp.append(i * l + l // 2)

xs = []
for _ in range(p):
    xs.append(int(input()))

count = [0] * len(tp)
ma = -10 ** 18
for x in xs:
    idx = len(tp) - 1
    mi = abs(tp[len(tp) - 1] - x)
    for i in range(len(tp) - 1, -1, -1):
        nd = abs(x - tp[i])
        if nd < mi:
            mi = nd
            idx = i
    ma = max(ma, mi)
    count[idx] += 1

print(ma)
print(max(count))
