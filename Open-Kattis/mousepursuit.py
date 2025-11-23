events = [input().split() for _ in range(int(input()))]
k = int(input())
cheese, glory = 0, 0
for et, *data in events:
    s, c, g = map(int, data)
    if s < k:
        if et == "CAUGHT":
            cheese += c
            glory += g
        else:
            cheese -= c
            glory -= g
print(cheese, glory)
