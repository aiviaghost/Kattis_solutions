from collections import defaultdict

cc = defaultdict(int)
for _ in range(int(input())):
    s, l = input().split()
    cc[s] += int(l)

ans = cc["S"] // 6 + (cc["S"] % 6 != 0) + cc["M"] // 8 + (cc["M"] % 8 != 0) + cc["L"] // 12 + (cc["L"] % 12 != 0)

print(ans)
