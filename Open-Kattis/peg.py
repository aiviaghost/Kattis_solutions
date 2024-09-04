board = [input() for _ in range(7)]

n, m = len(board), len(board[0])


def is_inside(x, y):
    return 0 <= x < m and 0 <= y < n


dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
dirs2 = [(2 * a, 2 * b) for a, b in dirs]

ans = 0
for row in range(n):
    for col in range(m):
        if board[row][col] == "o":
            for (dx, dy), (dx2, dy2) in zip(dirs, dirs2):
                if (
                    is_inside(col + dx2, row + dy2)
                    and board[row + dy][col + dx] == "o"
                    and board[row + dy2][col + dx2] == "."
                ):
                    ans += 1

print(ans)
