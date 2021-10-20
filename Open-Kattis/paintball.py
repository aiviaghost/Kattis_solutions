from sys import stdin, stdout, setrecursionlimit; setrecursionlimit(200000)
from math import gcd
from heapq import heapify, heappush, heappop
from functools import reduce
from itertools import permutations

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

n, m = map(int, stdin.readline().strip().split())
D = Dinitz(2 * n + 2)
edges = []
for _ in range(m):
	a, b = map(int, stdin.readline().strip().split())
	D.add_edge(a, n + b, 1)
	edges.append((a, n + b))
	D.add_edge(b, a + n, 1)
	edges.append((b, n + a))

edges.sort()

for i in range(1, n + 1):
	D.add_edge(0, i, 1)
	D.add_edge(n + i, 2 * n + 1, 1)

if D.max_flow(0, 2 * n + 1) < n:
	stdout.write("Impossible\n")
else:
	for edge in edges:
		u, v = edge
		if D.G[u][v] == 0:
			stdout.write(str(v - n) + "\n")
