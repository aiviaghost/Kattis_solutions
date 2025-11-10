ans = 7
for _ in range(int(input())):
    if input() == "Skru op!":
        ans = min(ans + 1, 10)
    else:
        ans = max(ans - 1, 0)
print(ans)
