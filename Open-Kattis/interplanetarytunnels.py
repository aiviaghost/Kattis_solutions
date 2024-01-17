from math import ceil

n, m = map(int, input().split())

INF = 10 ** 18

pa, pb = map(int, input().split())

dist = [INF] * n
adj = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

q = [pa]
dist[pa] = 0
for curr in q:
    for nx in adj[curr]:
        if dist[nx] == INF:
            dist[nx] = dist[curr] + 1
            q.append(nx)

print(ceil(dist[pb] / 2))
