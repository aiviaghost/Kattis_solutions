def bin_to_decimal(x):
    res = 0
    for i, d in enumerate(x[2:], start = 1):
        res += int(d) * 2 ** -i
    return res

n = int(input())
d = int(input())
pA = d / 8.0

decimal = bin_to_decimal(input())

for bits in range(1 << n):
    mask = [(bits >> i) & 1 for i in range(n)]
    a, b = 0, 1
    for bit in mask:
        c = a + pA * (b - a)
        if bit == 1:
            b = c
        else:
            a = c
    if a == decimal:
        print("".join("A" if bit == 1 else "B" for bit in mask))
        break
