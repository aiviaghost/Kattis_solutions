from collections import defaultdict
from sys import setrecursionlimit
setrecursionlimit(10 ** 6)

order = []
def dfs(vis, curr):
    if curr in vis:
        return
    vis.add(curr)
    for nx in adj[curr]:
        dfs(vis, nx)
    order.append(curr)

n = int(input())
adj = defaultdict(list)
for _ in range(n):
    f, deps = input().split(":")
    for dep in deps.strip().split():
        adj[dep].append(f)

dfs(set(), input())

print("\n".join(order[::-1]))
