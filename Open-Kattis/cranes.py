from sys import stdin, stdout, setrecursionlimit; setrecursionlimit(200000)
from math import gcd, sqrt
from heapq import heapify, heappush, heappop
from functools import reduce
from itertools import permutations, product

INF = int(1e20)

for _ in range(int(input())):
    C = int(input())
    cs = [tuple(map(int, input().split())) for _ in range(C)]
    ans = 0
    for p in product((0, 1), repeat=C):
        B = 0
        ok = True
        for i in range(C):
            if p[i]:
                for j in range(i + 1, C):
                    if p[j] and (cs[i][0] - cs[j][0]) ** 2 + (cs[i][1] - cs[j][1]) ** 2 <= (cs[i][2] + cs[j][2]) ** 2:
                        ok = False
                        break
                if not ok:
                    break
                B += cs[i][2] ** 2
        if ok:
            ans = max(B, ans)
    print(ans)
