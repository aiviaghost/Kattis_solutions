from string import ascii_letters

n, m = map(int, input().split())

maze = [input() for _ in range(n)]

starting_chars = [c for c in ascii_letters if c.isupper() and c != "X"]

starting_spots = []
for i in range(n):
    for j in range(m):
        if maze[i][j] in starting_chars:
            starting_spots.append((j, i))

neighbours = [(0, 1), (0, -1), (1, 0), (-1, 0)]

vis = [[False] * m for _ in range(n)]
req = 0
for sx, sy in starting_spots:
    ate = False
    vis[sy][sx] = True
    q = [(sx, sy)]

    for cx, cy in q:
        for dx, dy in neighbours:
            nx, ny = cx + dx, cy + dy
            if 0 <= nx < m and 0 <= ny < n and not vis[ny][nx] and (maze[ny][nx] == "." or maze[ny][nx] == " "):
                ate |= maze[ny][nx] == "."
                vis[ny][nx] = True
                q.append((nx, ny))

    if ate:
        req += 1

unvisited = 0
for i in range(n):
    for j in range(m):
        if maze[i][j] == "." and not vis[i][j]:
            unvisited += 1

print(req, unvisited)
