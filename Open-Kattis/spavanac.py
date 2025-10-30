from datetime import datetime, timedelta

new_time = datetime(2000, 1, 1, *map(int, input().split())) - timedelta(minutes=45)

print(new_time.hour, new_time.minute)
