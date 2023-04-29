from sys import stdin
from collections import defaultdict

inp = (line for line in stdin.read().split("\n"))
def nl():
    return next(inp)

N, L = map(int, nl().split())

mm = {name : state for name, state in (nl().split() for _ in range(N))}

adj = defaultdict(list)
for _ in range(L):
    a, b = nl().split(" -> ")
    adj[a].append(b)

known = False
maybe_known = False

m_looking_at = defaultdict(lambda: False)
q_looking_at = defaultdict(lambda: False)

for curr in mm.keys():
    for nx in adj[curr]:
        if mm[curr] == 'm':
            m_looking_at[nx] = True
        elif mm[curr] == '?':
            q_looking_at[nx] = True

for curr in mm.keys():
    for nx in adj[curr]:
        if mm[curr] == 'm' and mm[nx] == 'u':
            known = True
        elif m_looking_at[curr] and mm[curr] == '?' and mm[nx] == 'u':
            known = True
        elif mm[curr] == '?' and mm[nx] == '?':
            maybe_known = True
        elif mm[curr] == '?' and mm[nx] == 'u':
            maybe_known = True
        elif mm[curr] == 'm' and mm[nx] == '?':
            maybe_known = True

q = [name for name, state in mm.items() if state == 'm']
# should need to keep track of visited nodes but turns out there are no
# cycles starting from an 'm', going through only '?' and back to a '?'
for curr in q:
    for nx in adj[curr]:
        if mm[nx] == 'u':
            known = True
        elif mm[nx] == '?':
            q.append(nx)

if known:
    print(1)
elif maybe_known:
    print('?')
else:
    print(0)
