g, t, n = map(int, input().split())

tot = sum(map(int, input().split()))

print(int((g - t) * 0.9 - tot))
