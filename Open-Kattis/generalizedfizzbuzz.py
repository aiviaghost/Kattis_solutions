n, a, b = map(int, input().split())

ans = [0] * 3
for x in range(1, n + 1):
    if x % a == 0 and x % b == 0:
        ans[2] += 1
    elif x % a == 0:
        ans[0] += 1
    elif x % b == 0:
        ans[1] += 1

print(*ans)
