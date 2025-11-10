input()

votes = sorted(map(int, input().split()), reverse=True)
total = sum(votes)
second = votes[1]
ans = 0
while second * 2 < total and len(votes) > 2:
    second += votes.pop()
    ans += 1

print(ans if second * 2 > total else "IMPOSSIBLE TO WIN")
