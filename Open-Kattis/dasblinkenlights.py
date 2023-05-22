from math import gcd

def LCM(a, b):
    return (a * b) // gcd(a, b)

p, q, s = map(int, input().split())

print("yes" if 1 <= LCM(p, q) <= s else "no")
