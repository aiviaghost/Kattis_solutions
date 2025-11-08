mi, ma = 1e5, 0
for _ in range(int(input())):
    p = int(input())
    mi = min(p, mi)
    ma = max(ma, p)
print(max(0, mi - ma // 2))
