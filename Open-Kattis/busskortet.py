from bisect import bisect

denominations = [100, 200, 500]
dist = {0 : 0}
q = [0]

while q:
    next_q = []
    for curr in q:
        for denom in denominations:
            nx = curr + denom
            if nx not in dist and nx <= 10_000:
                dist[nx] = dist[curr] + 1
                next_q.append(nx)
    q = next_q

target = int(input())

if target in dist:
    print(dist[target])
else:
    possible = sorted(dist)
    print(dist[possible[bisect(possible, target)]])
