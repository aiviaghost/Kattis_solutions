from sys import stdin, stdout


n, m = map(int, stdin.readline().split(" "))

grid = []
for _ in range(n):
    grid.append(stdin.readline().rstrip())

dist = [[-1] * m for _ in range(n)]
startX, startY = 0, 0
dist[startY][startX] = 0
curr_layer = [[startY, startX]]

def get_neighbors(n):
    return [(n, 0), (0, n), (-n, 0), (0, -n)]

while curr_layer: 
    nextLayer = []
    for currY, currX in curr_layer:
        for toNeigh in get_neighbors(int(grid[currY][currX])):
            nx = currX + toNeigh[1]
            ny = currY + toNeigh[0]
            if 0 <= nx < m and 0 <= ny < n:
                if dist[ny][nx] == -1:
                    dist[ny][nx] = dist[currY][currX] + 1
                    nextLayer.append((ny, nx))
    curr_layer = nextLayer

stdout.write(str(dist[n - 1][m - 1]))
