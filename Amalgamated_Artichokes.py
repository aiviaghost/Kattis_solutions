from sys import stdin, stdout
from math import sin, cos

p, a, b, c, d, n = map(int, stdin.readline().split())

def price(k):
    return p * (sin(a * k + b) + cos(c * k + d) + 2)

prices = [price(i) for i in range(1, n + 1)]

max_decline, max_val, max_val_index = 0, 0, 0

for i in range(n):
    if prices[i] > max_val:
        max_val = prices[i]
        max_val_index = i

    max_decline = max(max_val - prices[i], max_decline)
    
stdout.write(str(max_decline))
