n, m = map(int, input().split())

rungs = []
for _ in range(m):
    a = int(input())
    rungs.append((a, a + 1))

perm = [0] * n
for i in range(1, n + 1):
    curr = i
    for l, r in rungs:
        if curr == l:
            curr = r
        elif curr == r:
            curr = l
    perm[curr - 1] = i

print("\n".join(map(str, perm)))
