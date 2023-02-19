from sys import stdin

k = int(input())

par = {}

for line in stdin:
    if "-1" in line:
        break
    a, *children = map(int, line.split())
    for c in children:
        par[c] = a

curr = k
path = [curr]
while curr in par:
    curr = par[curr]
    path.append(curr)

print(*path)
