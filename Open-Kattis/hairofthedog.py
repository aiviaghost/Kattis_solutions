days = [input() for _ in range(int(input()))]
print(sum(day1 == "drunk" and day2 == "sober" for day1, day2 in zip(days, days[1:])))
