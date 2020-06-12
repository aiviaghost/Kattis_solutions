from sys import stdin, stdout
from math import sin, cos

p, a, b, c, d, n = map(int, stdin.readline().split())

def price(k):
    return p * (sin(a * k + b) + cos(c * k + d) + 2)

prices = [price(i) for i in range(1, n + 1)]

