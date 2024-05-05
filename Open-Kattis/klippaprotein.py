s = input()
k = int(input())

ans = 10 ** 20
for target_c in set(s):
    cuts = 0

    i = 0
    while i < len(s):
        if s[i] == target_c:
            i += 1
        else:
            cuts += 1
            i += k

    ans = min(ans, cuts)

print(ans)
