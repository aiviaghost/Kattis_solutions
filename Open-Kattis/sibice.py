n, w, h = map(int, input().split())
for _ in range(n):
    print("DA" if int(input()) <= (w ** 2 + h ** 2) ** .5 else "NE")
