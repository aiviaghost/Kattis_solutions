n, m = map(int, input().split())

mines = []
for i in range(n):
    s = input()
    for j in range(m):
        if s[j] == "*":
            mines.append((i, j))

print(len(mines))
for i, j in mines:
    print(i + 1, j + 1)
