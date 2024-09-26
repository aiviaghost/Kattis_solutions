from collections import defaultdict

n = int(input())
perm = [int(i) - 1 for i in input().split()]

freq = defaultdict(int)
for i, p in enumerate(perm):
    freq[(i - p) % n] += 1

shift = max(freq.items(), key=lambda x:(x[1], -x[0]))[0]
ans = sum((i - shift) % n == p for i, p in enumerate(perm))

print(shift, ans)
