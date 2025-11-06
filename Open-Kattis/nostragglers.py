ans = 0
for _ in range(int(input())):
    _, direction, num = input().split()
    ans += int(num if direction == "IN" else f"-{num}")
print(ans if ans > 0 else "NO STRAGGLERS")
