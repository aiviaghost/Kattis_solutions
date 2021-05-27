from sys import stdin, stdout
from math import sin, cos

p, a, b, c, d, n = map(int, stdin.readline().split())

def price(k):
    return p * (sin(a * k + b) + cos(c * k + d) + 2)

prices = [price(i) for i in range(1, n + 1)]

max_decline, max_val = 0, 0

for price in prices:
    max_val = max(price, max_val)
    max_decline = max(max_val - price, max_decline)
    
stdout.write(str(max_decline))
