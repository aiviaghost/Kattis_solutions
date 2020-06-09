from sys import stdin, stdout


N = int(stdin.readline())

board = []
for _ in range(N):
    board.append([c for c in stdin.readline().rstrip()])


kx, ky = 0, 0
for i in range(N):
    for j in range(N):
        if board[i][j] == "K":
            kx = j
            ky = i


dist = [[-1] * N for _ in range(N)]
dist[ky][kx] = 0
neighbours = [(1, 2), (1, -2), (-1, 2), (-1, -2), (2, 1), (2, -1), (-2, 1), (-2, -1)]
current_layer = [(kx, ky)]

while current_layer:
    next_layer = []
    for currentX, currentY in current_layer:
        for neighbour in neighbours:
            nextX = currentX + neighbour[0]
            nextY = currentY + neighbour[1]
            if 0 <= nextX < N and 0 <= nextY < N:
                if dist[nextY][nextX] == -1 and board[nextY][nextX] != "#":
                    dist[nextY][nextX] = dist[currentY][currentX] + 1
                    next_layer.append((nextX, nextY))

    current_layer = next_layer

stdout.write(str(dist[0][0]))
