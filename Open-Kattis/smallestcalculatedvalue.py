a, b, c = map(int, input().split())

ops = ["+", "-", "//", "*"]

mi = 10 ** 18
for op1 in ops:
    for op2 in ops:
        if op1 == "//" and a % b != 0:
            continue
        res1 = eval(f"{a}{op1}{b}")
        if op2 == "//" and res1 % c != 0:
            continue
        res = eval(f"{res1}{op2}{c}")
        if res >= 0:
            mi = min(mi, res)

print(mi)
