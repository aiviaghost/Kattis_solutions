xs = []
ys = []
ps = set()
for _ in range(3):
    x, y = map(int, input().split())
    xs.append(x)
    ys.append(y)
    ps.add((x, y))

min_x = min(xs)
max_x = max(xs)
min_y = min(ys)
max_y = max(ys)

a = {(min_x, min_y), (min_x, max_y), (max_x, min_y), (max_x, max_y)}

print(*list(a - ps)[0])
