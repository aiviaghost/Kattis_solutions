n = int(input())

grid = [input() for _ in range(n)]

INF = 10 ** 18
dist = [[INF] * n for _ in range(n)]

q = []
for i in range(n):
    for j in range(n):
        if grid[i][j] == 'H':
            q.append((j, i))
            dist[i][j] = 0

adj = [
    (0, -1),
    (0, 1),
    (1, 0),
    (-1, 0)
]

for cx, cy in q:
    for dx, dy in adj:
        nx, ny = cx + dx, cy + dy
        if 0 <= nx < n and 0 <= ny < n and dist[ny][nx] == INF:
            dist[ny][nx] = dist[cy][cx] + 1
            q.append((nx, ny))

spies = []
for i in range(n):
    for j in range(n):
        if grid[i][j] == 'S':
            spies.append(dist[i][j])

print(max(spies))
