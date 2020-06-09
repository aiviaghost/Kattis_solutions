from sys import stdin, stdout


n, m = map(int, stdin.readline().split(" "))

matrix = []
for i in range(n):
    matrix.append([c for c in stdin.readline()])


h1, h2 = [0, 0], [0, 0]

h1_found = False
for i in range(n):
    for j in range(m):
        if not h1_found and matrix[i][j] == "H":
            h1[0] = j
            h1[1] = i
            h1_found = True
        elif matrix[i][j] == "H":
            h2[0] = j
            h2[1] = i
startX, startY = h1[0], h1[1]


neighbours = [(-2, -1), (-2, 1), (2, -1), (2, 1), (1, -2), (1, 2), (-1, -2), (-1, 2)]
dist = [[-1] * m for _ in range(n)]
curLayer = [(startY, startX)]
dist[startY][startX] = 0

while curLayer: 
    nextLayer = []
    for currY, currX in curLayer:
        for toNeigh in neighbours:
            nx = currX + toNeigh[1]
            ny = currY + toNeigh[0]
            if 0 <= nx < m and 0 <= ny < n:
                if matrix[ny][nx] != "#" and dist[ny][nx] == -1:
                    dist[ny][nx] = dist[currY][currX] + 1
                    nextLayer.append((ny, nx))
    curLayer = nextLayer


stdout.write("JA" if dist[h2[1]][h2[0]] != -1 else "NEJ")
