value = {
    "A" : (11, 11),
    "K" : (4, 4),
    "Q" : (3, 3),
    "J" : (20, 2),
    "T" : (10, 10),
    "9" : (14, 0),
    "8" : (0, 0),
    "7" : (0, 0)
}

N, B = input().split()
ans = 0
for _ in range(4 * int(N)):
    num, suit = iter(input())
    ans += value[num][suit != B]

print(ans)
