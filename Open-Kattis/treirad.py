n = int(input())
a, b, c = 1, 2, 3
ans = 0
while a * b * c < n:
    ans += 1
    a, b, c = b, c, c + 1
print(ans)
