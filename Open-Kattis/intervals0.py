n, k = map(int, input().split())

overlap = [0] * 24

for _ in range(n):
    a, b = map(int, input().split())
    for i in range(a, b):
        overlap[i] += 1

print(sum(x >= k for x in overlap))
