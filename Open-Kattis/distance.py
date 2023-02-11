from sys import stdin

inp = (line for line in stdin.read().split("\n"))

def nl():
    return next(inp)

n = int(nl())


xs = []
ys = []
for _ in range(n):
    x, y = map(int, nl().split())
    xs.append(x)
    ys.append(y)

xs.sort()
ys.sort()

pref_x = [0] * len(xs)
pref_x[0] = xs[0]
for i in range(1, len(xs)):
    pref_x[i] = pref_x[i - 1] + xs[i]

pref_y = [0] * len(ys)
pref_y[0] = ys[0]
for i in range(1, len(ys)):
    pref_y[i] = pref_y[i - 1] + ys[i]

tot = 0
for i in range(len(xs) - 1, 0, -1):
    tot += i * xs[i] - pref_x[i - 1]
for i in range(len(xs) - 1, 0, -1):
    tot += i * ys[i] - pref_y[i - 1]

print(tot)
