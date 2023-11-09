from math import prod

r, s, m, d, n = map(int, input().split())

counts = list(map(int, input().split()))

starters = [set(map(lambda x: int(x) - 1, input().split()[1:])) for _ in range(s)]
mains = [set(map(lambda x: int(x) - 1, input().split()[1:])) for _ in range(m)]
desserts = [set(map(lambda x: int(x) - 1, input().split()[1:])) for _ in range(d)]

invalid = set((t := [tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(n)]) + [(b, a) for a, b in t])

ans = 0
for i, sa in enumerate(starters):
    for j, ma in enumerate(mains, start=s):
        for k, de in enumerate(desserts, start=s+m):
            if ans > 10 ** 18 or (i, j) in invalid or (i, k) in invalid or (j, k) in invalid:
                continue
            ans += prod(counts[i] for i in sa | ma | de)

print(ans if ans <= 10 ** 18 else "too many")
