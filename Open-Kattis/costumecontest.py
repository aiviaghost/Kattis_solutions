n = int(input())

count = {}
for _ in range(n):
    costume = input()
    if costume in count:
        count[costume] += 1
    else:
        count[costume] = 1

best = []
min_count = 1e4
for k, v in count.items():
    if (v < min_count):
        best.clear()
        best.append(k)
        min_count = v
    elif v == min_count:
        best.append(k)

best.sort()
for b in best:
    print(b)
