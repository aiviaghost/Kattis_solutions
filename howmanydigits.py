from sys import stdin, stdout
from math import floor, log, pi


def fac(n):
    prod = 1
    for i in range(2, n + 1):
        prod *= i
    return prod

def stirling(n):
    return floor(((n + 0.5) * log(n) - n + 0.5 * log(2 * pi)) / log(10)) + 1

for line in stdin:
    n = int(line)
    if (n < 10):
        stdout.write(str(len(str(fac(n)))))
    else:
        stdout.write(str(stirling(n)))
    
    stdout.write("\n")
