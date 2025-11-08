N = int(input())
out = []
for i in range(N):
    for j, d in zip(range(N), input().split()):
        if d != "-1":
            out.append((i + 1, j + 1, d))
print(len(out))
for x in out:
    print(*x)
