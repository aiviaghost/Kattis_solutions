occupied_days = [0] * 365
for _ in range(int(input())):
    start, end = map(int, input().split())
    occupied_days[start : end + 1] = [1] * (end - start + 1)
print(sum(occupied_days))
