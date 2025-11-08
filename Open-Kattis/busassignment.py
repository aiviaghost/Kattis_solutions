curr = 0
ans = 0
for _ in range(int(input())):
    a, b = map(int, input().split())
    curr += b - a
    ans = max(ans, curr)
print(ans)
