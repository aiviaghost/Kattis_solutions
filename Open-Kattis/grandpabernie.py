from collections import defaultdict

n = int(input())
lookup = defaultdict(list)

for _ in range(n):
    s, y = input().split()
    lookup[s].append(int(y))

for _, v in lookup.items():
    v.sort()

q = int(input())
for _ in range(q):
    s, k = input().split()
    print(lookup[s][int(k) - 1])
