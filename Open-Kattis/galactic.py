from sys import stdin, stdout, setrecursionlimit; setrecursionlimit(200000)
from math import gcd, sqrt
from heapq import heapify, heappush, heappop
from functools import reduce
from itertools import permutations, product

INF = int(1e20)

class Line:
    def __init__(self, x1, y1, x2, y2):
        self.x1 = x1
        self.k = (y1 - y2) / (x1 - x2) if (x1 - x2) != 0 else INF
        self.b = y1 - self.k * x1 if self.k != INF else 0
    def __eq__(self, other):
        return self.k == other.k and (self.b == other.b if self.k != INF else self.x1 == other.x1)
    def __ne__(self, other):
        return not self.__eq__(other)
    def parallel_to(self, other):
        return self.k == other.k and (self.b != other.b if self.k != INF else self.x1 != other.x1)

W, N = map(int, input().split())
inp = []
for _ in range(N):
    inp.append(Line(*map(int, input().split())))
lines = []
for i in range(N):
    unique = True
    for j in range(i + 1, N):
        if inp[i] == inp[j]:
            unique = False
            break
    if unique:
        lines.append(inp[i])
if len(lines) >= 2 and all(all(i.parallel_to(j) for j in lines if i != j) for i in lines):
    ans = 0
    S = len(lines) + 1
    if S >= W:
        print(ans)
    else:
        ans += 1
        S *= 2
        while S + 2 * (ans - 1) < W:
            ans += 1
        print(ans)
else:
    ans = 0
    while 2 * (len(lines) + ans) < W:
        ans += 1
    print(ans)
