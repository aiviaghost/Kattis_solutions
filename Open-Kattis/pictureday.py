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


n = int(input())
ga, gb = map(int, input().split())
a, b, c = map(int, input().split())

A = [list(map(int, input().split()[1:])) for _ in range(ga)]
B = [set(map(int, input().split()[1:])) for _ in range(gb)]

size = ga + gb + 2
flow = Dinitz(size)
s, t = size - 2, size - 1

for i in range(ga):
    flow.add_edge(s, i, a)

for i in range(gb):
    flow.add_edge(ga + i, t, b)

for i, g1 in enumerate(A):
    for j, g2 in enumerate(B):
        for p in g1:
            if p in g2:
                flow.add_edge(i, ga + j, c)

print(flow.max_flow(s, t))
