

n = int(input())
names = []
lows = {}
highs = {}
for _ in range(n):
    data = input().split()
    name = data[0]
    names.append(name)
    high, low = map(float, data[1:])
    lows[name] = low
    highs[name] = high

best_names = []
best = 1e9
for name in names:
    curr = highs[name]
    curr_names = [name]
    low_cp = lows.copy()
    del low_cp[name]
    for _ in range(3):
        n, s = sorted(low_cp.items(), key = lambda x: x[1])[0]
        del low_cp[n]
        curr_names.append(n)
        curr += s
    if curr < best:
        best = curr
        best_names = curr_names

print(best)
for n in best_names:
    print(n)
