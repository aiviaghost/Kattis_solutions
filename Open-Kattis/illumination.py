from sys import setrecursionlimit

setrecursionlimit(10 ** 7)

class Sat:
    def __init__(self, no_vars):
        self.size = no_vars*2
        self.no_vars = no_vars
        self.adj = [[] for _ in range(self.size)]
        self.back = [[] for _ in range(self.size)]
    def add_imply(self, i, j):
        self.adj[i].append(j)
        self.back[j].append(i)
    def add_or(self, i, j):
        self.add_imply(i^1, j)
        self.add_imply(j^1, i)
    def add_xor(self, i, j):
        self.add_or(i, j)
        self.add_or(i^1, j^1)
    def add_eq(self, i, j):
        self.add_xor(i, j^1)
    
    def dfs1(self, i):
        if i in self.marked: return
        self.marked.add(i)
        for j in self.adj[i]:
            self.dfs1(j)
        self.stack.append(i)

    def dfs2(self, i):
        if i in self.marked: return
        self.marked.add(i)
        for j in self.back[i]:
            self.dfs2(j)
        self.comp[i] = self.no_c

    def is_sat(self):
        self.marked = set()
        self.stack = []
        for i in range(self.size):
            self.dfs1(i)
        self.marked = set()
        self.no_c = 0
        self.comp = [0]*self.size
        while self.stack:
            i = self.stack.pop()
            if i not in self.marked:
                self.no_c += 1
                self.dfs2(i)
        for i in range(self.no_vars):
            if self.comp[i*2] == self.comp[i*2+1]:
                return False
        return True

n, r, k = map(int, input().split())

lamps = [(i, r, c) for i, (r, c) in enumerate(
            map(int, input().split()) for _ in range(k)
        )]

sat = Sat(k)

"""
!(a & b) = !a | !b
horizontal = true
vertical = false
sat.add_or(2 * a, 2 * b) -> a | b
sat.add_or(2 * a + 1, 2 * b + 1) -> !a | !b
r1 == r2 -> same row -> at most one can be horizontal -> not both -> !(horizontal & horizontal) -> !(true & true) -> !true | !true -> false | false -> sat.add_or(2 * a + 1, 2 * b + 1)
c1 == c2 -> same col -> at most one can be vertical -> not both -> !(vertical & vertical) -> !(false & false) -> !false | !false -> true | true -> sat.add_or(2 * a, 2 * b)
"""
for i, r1, c1 in lamps:
    for j, r2, c2 in lamps:
        if i != j:
            if r1 == r2 and abs(c1 - c2) <= 2 * r - 1:
                sat.add_or(2 * i + 1, 2 * j + 1)
            elif c1 == c2 and abs(r1 - r2) <= 2 * r - 1:
                sat.add_or(2 * i, 2 * j)

print(1 if sat.is_sat() else 0)
