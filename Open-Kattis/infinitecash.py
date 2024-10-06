s = int(input(), 2)
d = int(input(), 2)
m = int(input(), 2)

t = m
for day in range(min(d, 999)):
    if t == 0:
        print(bin(day)[2:])
        exit()
    t >>= 1

if s >> (d - 1) >= 1:
    print("Infinite money!")
    exit()

day_counter = 0
while 1:
    for day in range(d):
        if m == 0:
            print(bin(day_counter + day)[2:])
            exit()
        m >>= 1
    m += s

    day_counter += d
