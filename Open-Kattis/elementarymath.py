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

ab = []

n = int(input())
cc = defaultdict(lambda: n + len(cc))
for _ in range(n):
    a, b = map(int, input().split())
    ab.append((a, b))
    cc[a * b]
    cc[a + b]
    cc[a - b]

size = n + len(cc) + 2
flow = Dinitz(size)
s, t = size - 2, size - 1

for i in range(n):
    flow.add_edge(s, i, 1)

for i in cc.values():
    flow.add_edge(i, t, 1)

for (i, (a, b)) in enumerate(ab):
    for nx in {cc[a * b], cc[a + b], cc[a - b]}:
        flow.add_edge(i, nx, 1)

max_flow = flow.max_flow(s, t)

if max_flow < n:
    print("impossible")
else:
    for (i, (a, b)) in enumerate(ab):
        if flow.G[i][cc[a * b]] == 0:
            print(f"{a} * {b} = {a * b}")
        elif flow.G[i][cc[a + b]] == 0:
            print(f"{a} + {b} = {a + b}")
        elif flow.G[i][cc[a - b]] == 0:
            print(f"{a} - {b} = {a - b}")
