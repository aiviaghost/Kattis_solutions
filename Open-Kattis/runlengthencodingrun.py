a, b = input().split()
if a == "E":
    output = ""
    prev = ""
    count = 1
    for c in b:
        if c == prev:
            count += 1
        else:
            output += prev
            output += str(count)
            count = 1
            prev = c
    output += prev
    output += str(count)
    print(output[1:])
else:
    output = ""
    num = False
    prev = ""
    for c in b:
        if num:
            output += prev * int(c)
        else:
            prev = c
        num = not num
    print(output)