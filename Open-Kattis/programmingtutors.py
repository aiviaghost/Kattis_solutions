from sys import stdin, stdout, setrecursionlimit; setrecursionlimit(200000)
from math import gcd
from heapq import heapify, heappush, heappop
from functools import reduce
from itertools import permutations, product

INF = int(1e20)

from collections import defaultdict
class Dinitz:
    def __init__(self, sz, INF=10**10):
        self.G = [defaultdict(int) for _ in range(sz)]
        self.sz = sz
        self.INF = INF

    def add_edge(self, i, j, w):
        self.G[i][j] += w

    def bfs(self, s, t):
        level = [0]*self.sz
        q = [s]
        level[s] = 1
        while q:
            q2 = []
            for u in q:
                for v, w in self.G[u].items():
                    if w and level[v] == 0:
                        level[v] = level[u] + 1
                        q2.append(v)
            q = q2
        self.level = level
        return level[t] != 0

    def dfs(self, s, t, FLOW):
        if s in self.V: return 0
        if s == t: return FLOW
        self.V.add(s)
        L = self.level[s]
        for u, w in self.G[s].items():
            if u in self.dead: continue
            if w and L+1==self.level[u]:
                F = self.dfs(u, t, min(FLOW, w))
                if F:
                    self.G[s][u] -= F
                    self.G[u][s] += F
                    return F
        self.dead.add(s)
        return 0
    

    def max_flow(self, s, t):
        flow = 0
        while self.bfs(s, t):
            self.dead = set()
            while True:
                self.V = set()    
                pushed = self.dfs(s, t, self.INF)
                if not pushed: break
                flow += pushed
        return flow

n = int(stdin.readline().strip())

students, tutors = [], []
for _ in range(n):
    x, y = map(int, stdin.readline().strip().split())
    students.append((x, y))
for _ in range(n):
    x, y = map(int, stdin.readline().strip().split())
    tutors.append((x, y))

def m_dist(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

edges = [(u[0], v[0] + n, m_dist(*u[1], *v[1])) for u, v in product(enumerate(students), enumerate(tutors))]

def solve(max_w):
    D = Dinitz(2 * n + 2)
    for u, v, w in edges:
        if w <= max_w:
            D.add_edge(u, v, 1)
    for i in range(n):
        D.add_edge(2 * n, i, 1)
        D.add_edge(n + i, 2 * n + 1, 1)
    return D.max_flow(2 * n, 2 * n + 1)

lb, rb, mid = 0, 10**9, -1
while rb - lb > 1:
    mid = lb + (rb - lb) // 2
    if solve(mid) < n:
        lb = mid
    else:
        rb = mid

while solve(mid) == n:
    mid -= 1

while solve(mid) < n:
    mid += 1

stdout.write(str(mid) + "\n")
