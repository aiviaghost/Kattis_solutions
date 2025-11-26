s1 = input()
s2 = input()
s1 = s1.rjust(len(s2), "0")

ans = 0
for i in range(len(s1)):
    if s1[i] != s2[i]:
        break
    ans += s1[i] == "1"
else:
    ans -= 1
ans += len(s1) - i

print(ans)
