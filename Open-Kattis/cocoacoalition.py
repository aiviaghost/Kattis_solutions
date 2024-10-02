n, m, a = map(int, input().split())

ans = 3

for col in range(1, n + 1):
    rect = col * m

    if rect == a:
        ans = 1
    
    if a % col == 0 and a // col <= m:
        ans = min(ans, 2)

    if a - rect > 0 and (a - rect) % (n - col) == 0 and (a - rect) // (n - col) <= m:
        ans = min(ans, 2)

n, m = m, n

for col in range(1, n + 1):
    rect = col * m

    if rect == a:
        ans = 1
    
    if a % col == 0 and a // col <= m:
        ans = min(ans, 2)

    if a - rect > 0 and (a - rect) % (n - col) == 0 and (a - rect) // (n - col) <= m:
        ans = min(ans, 2)

print(ans)
