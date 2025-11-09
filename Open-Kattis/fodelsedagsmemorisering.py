from collections import defaultdict

n = int(input())

d = defaultdict(lambda: (-1, ""))
for _ in range(n):
    name, score, date = input().split()
    d[date] = max(d[date], (int(score), name))

print(len(d))
out = []
for (_, name) in d.values():
    out.append(name)
print(*sorted(out), sep="\n")
