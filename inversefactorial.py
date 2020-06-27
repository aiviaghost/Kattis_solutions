from sys import stdin, stdout
from math import floor, ceil, log, log10, sqrt, pi, e


factorial = stdin.readline()
len_fac = len(factorial) - 1


def digits(n):
    return floor(0.5 * log10(2 * pi * n) + n * log10(n / e))

# binary-search
l, r, mid = 0, 1e60, -1
while (abs(l - r) > 0):
    mid = l + (r - l) // 2
    if (digits(mid) < len_fac):
        l = mid + 1
    else:
        r = mid


def fac(n):
    prod = 1
    for i in range(2, int(n) + 1):
        prod *= i
    return prod

def stirling(n):
    return floor(((n + 0.5) * log(n) - n + 0.5 * log(2 * pi)) / log(10)) + 1

if (mid < 10):
    while (True):
        temp = fac(mid)
        if (temp == int(factorial)):
            break
        elif temp > int(factorial):
            mid -= 1
        else:
            mid += 1
else:
    while (True):
        temp = stirling(mid)
        if (temp == len_fac):
            break
        elif temp > len_fac:
            mid -= 1
        else:
            mid += 1

stdout.write(str(mid)[: -2])
