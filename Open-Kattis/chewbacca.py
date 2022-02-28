from sys import stdin, stdout, setrecursionlimit; setrecursionlimit(200000)
from math import ceil, floor, gcd, sqrt
from heapq import heapify, heappush, heappop
from functools import reduce
from itertools import permutations, product

INF = int(1e20)

def par(k, x):
    return ceil((x - 1) / k)

def depth(K, x):
    d = 0
    while x != 1:
        x = par(K, x)
        d += 1
    return d

buffer = []

N, K, Q = map(int, input().split())
for _ in range(Q):
    x, y = map(int, input().split())
    ans = 0
    dx, dy = depth(K, x), depth(K, y)
    while x != y:
        if dx < dy:
            y = par(K, y)
            dy -= 1
        else:
            x = par(K, x)
            dx -= 1
        ans += 1
    buffer.append(ans)

print("\n".join(map(str, buffer)))
