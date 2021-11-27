from sys import stdin, stdout, setrecursionlimit; setrecursionlimit(200000)
from math import gcd, sqrt
from heapq import heapify, heappush, heappop
from functools import reduce
from itertools import permutations, product

INF = int(1e20)

X = int(input())
q = list(input())
w, m = 0, 0
while q:
    if q[0] == "W" and abs(w + 1 - m) <= X:
        w += 1
        q.pop(0)
        continue
    elif q[0] == "M" and abs(m + 1 - w) <= X:
        m += 1
        q.pop(0)
        continue
    if q[1] == "W" and abs(w + 1 - m) <= X:
        w += 1
        q.pop(1)
        continue
    elif q[1] == "M" and abs(m + 1 - w) <= X:
        m += 1
        q.pop(1)
        continue
    break
    
print(w + m)
