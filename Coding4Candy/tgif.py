current_date = [c for c in input().split(" ")]
jan_1st = input()

months = {"JAN" : 0, "FEB" : 1, "MAR" : 2, "APR" : 3, "MAY" : 4, "JUN" : 5, "JUL" : 6, "AUG" : 7, "SEP" : 8, "OCT" : 9, "NOV" : 10, "DEC" : 11}
days_each_month = {0 : 31, 1 : 28, 2 : 31, 3 : 30, 4 : 31, 5 : 30, 6 : 31, 7 : 31, 8 : 30, 9 : 31, 10 : 30, 11 : 31}

days_since_jan_1st = 0
for i in range(months[current_date[1]]):
    days_since_jan_1st += days_each_month[i]
days_since_jan_1st += int(current_date[0])

normal_year = days_since_jan_1st
leap_year = days_since_jan_1st

if months[current_date[1]] > 1:
    leap_year += 1

week_days = {"MON" : 0, "TUE" : 1, "WED" : 2, "THU" : 3, "FRI" : 4, "SAT" : 5, "SUN" : 6}

if (week_days[jan_1st] + (normal_year)) % 7 == 5 and (week_days[jan_1st] + (leap_year)) % 7 != 5:
    print("not sure")
elif (week_days[jan_1st] + (normal_year)) % 7 != 5 and (week_days[jan_1st] + (leap_year)) % 7 == 5:
    print("not sure")
elif (week_days[jan_1st] + (normal_year)) % 7 != 5 and (week_days[jan_1st] + (leap_year)) % 7 != 5:
    print(":(")
elif (week_days[jan_1st] + (normal_year)) % 7 == 5 and (week_days[jan_1st] + (leap_year)) % 7 == 5:
    print("TGIF")
