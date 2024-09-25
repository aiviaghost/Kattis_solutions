from math import comb, factorial as fac

n = int(input())

large = False

total = 0
for i in range(1, n + 1):
    total += comb(n, i) * fac(i)
    if total > 10 ** 9:
        large = True
        break

if large:
    print("JUST RUN!!")
else:
    print(total)