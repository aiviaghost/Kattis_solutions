R, C = map(int, input().split())

grid = [input() for _ in range(R)]

ans = [0] * 5
for i in range(R - 1):
    for j in range(C - 1):
        spot = [grid[i][j], grid[i + 1][j], grid[i][j + 1], grid[i + 1][j + 1]]

        if any(c == "#" for c in spot):
            continue
    
        ans[sum(c == "X" for c in spot)] += 1

print(*ans, sep="\n")
