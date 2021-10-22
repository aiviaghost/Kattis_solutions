from sys import stdin, stdout, setrecursionlimit; setrecursionlimit(200000)
from math import gcd, sqrt
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

itr = (line for line in stdin.read().split('\n'))
INP = lambda: next(itr)
def readInts(): return [int(_) for _ in INP().split()]
def readFloats(): return [float(_) for _ in INP().split()]

while True:
	try:
		n, m, s, v = readInts()
		gophers, holes = [], []
		for _ in range(n):
			x, y = readFloats()
			gophers.append((x, y))
		for _ in range(m):
			x, y = readFloats()
			holes.append((x, y))

		def dist(x1, y1, x2, y2):
			return sqrt((x1 - x2)**2 + (y1 - y2)**2)

		D = Dinitz(n + m + 2)
		edges = [(i[0], n + j[0]) for i, j in product(*map(enumerate, (gophers, holes))) if dist(*i[1], *j[1]) <= s * v]
		for u, v in edges:
			D.add_edge(u, v, 1)
		for i in range(n):
			D.add_edge(n + m, i, 1)
		for i in range(m):
			D.add_edge(n + i, n + m + 1, 1)

		stdout.write(str(n - D.max_flow(n + m, n + m + 1)) + "\n")
	except:
		break
