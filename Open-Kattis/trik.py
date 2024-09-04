cups = [1, 0, 0]
for c in input().lower():
    if c == "a":
        cups[0], cups[1] = cups[1], cups[0]
    elif c == "b":
        cups[1], cups[2] = cups[2], cups[1]
    else:
        cups[0], cups[2] = cups[2], cups[0]

print(max(range(3), key=lambda x: cups[x]) + 1)
