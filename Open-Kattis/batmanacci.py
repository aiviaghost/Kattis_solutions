n, k = map(int, input().split())

fibs = [0, 1]
while len(fibs) <= n:
    fibs.append(fibs[-1] + fibs[-2])

l = ["", "n", "a", "na", "ana", "naana", "ananaana"]
known = [s.upper() for s in l]

if n < len(known):
    print(known[n][k - 1])
    exit(0)

while n >= len(known):
    if k <= fibs[n - 2]:
        n -= 2
    else:
        k -= fibs[n - 2]
        n -= 1

print(known[n][k - 1])
