n = int(input())

running = False
tot = 0
prev = 0
for _ in range(n):
    curr = int(input())
    if running:
        tot += curr - prev
        running = False
    else:
        running = True
        prev = curr

if running:
    print("still running")
else:
    print(tot)
