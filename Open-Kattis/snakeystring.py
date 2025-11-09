R, C = map(int, input().split())

ans = [None] * C
for _ in range(R):
    for i, c in enumerate(input()):
        if c.isalpha():
            ans[i] = c

print("".join(ans))
