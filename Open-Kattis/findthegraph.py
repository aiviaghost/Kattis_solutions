n = int(input())

def query(points):
    print(f"? {len(points)}", *points, flush=True)
    return int(input())

grid = [[0] * n for _ in range(n)]

single_queries = [query([i + 1]) for i in range(n)]

for i in range(n):
    for j in range(i + 1, n):
        if query([i + 1, j + 1]) != single_queries[i] + single_queries[j]:
            grid[i][j] = 1
            grid[j][i] = 1

print("!")
print("\n".join(" ".join(map(str, row)) for row in grid))
