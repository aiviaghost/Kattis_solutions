from sys import stdin

cas = 1
for line in stdin.read().strip().split("\n"):
    x, y = map(int, line.split())
    days = 0
    while not (x == 0 and y == 0):
        x = (x + 1) % 365
        y = (y + 1) % 687
        days += 1
    print(f"Case {cas}:", days)
    cas += 1
