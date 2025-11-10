n, m, k = map(int, input().split())

grid = [["."] * m for _ in range(n)]
for _ in range(k):
    y, x = map(int, input().split())
    grid[y - 1][x - 1] = "*"

print(*("".join(row) for row in grid), sep="\n")
