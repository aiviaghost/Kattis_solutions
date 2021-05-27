from sys import stdin, stdout

W, H = map(int, stdin.readline().split())

board = []
for _ in range(H):
    board.append(stdin.readline())

start_x, start_y = 0, 0
for i in range(H):
    for j in range(W):
        if (board[i][j] == "P"):
            start_x, start_y = j, i
            i = H
            break

neighbours = ((0, 1), (0, -1), (1, 0), (-1, 0))
current_layer = []
current_layer.append((start_x, start_y))
vis = [[-1] * W for _ in range(H)]
gold_count = 0

def inside(x, y):
    return 0 <= x < W and 0 <= y < H

while (current_layer):
    next_layer = []
    for x_pos, y_pos in current_layer:
        if board[y_pos][x_pos] == "G":
            gold_count += 1

        is_safe = True
        for i, j in neighbours:
            if inside(x_pos + i, y_pos + j) and board[y_pos + j][x_pos + i] == "T":
                is_safe = False
                break

        if is_safe:
            for i, j in neighbours:
                if inside(x_pos + i, y_pos + j) and vis[y_pos + j][x_pos + i] == -1 and board[y_pos + j][x_pos + i] != "#":
                    vis[y_pos + j][x_pos + i] = 1
                    next_layer.append((x_pos + i, y_pos + j))
        
    current_layer = next_layer

stdout.write(str(gold_count))
