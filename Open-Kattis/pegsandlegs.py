from sys import stdin

inp = (line for line in stdin.read().split("\n"))

def nl():
    return next(inp)

l, p = map(int, nl().split())

expected_value = [0] * (l + p)
for i in range(l):
    expected_value[i] = int(nl())

adj = [[] for _ in range(l + p)]
in_deg = [0] * (l + p)
out_deg = [0] * (l + p)

probs = [(1, 0) for _ in range(l + p)]
p_success = [0] * (l + p)

for i in range(p):
    pl, pr, left, right = nl().split()
    pl, pr = float(pl), float(pr)
    probs[l + i] = (pl, pr)
    left, right = int(left) - 1, int(right) - 1
    in_deg[l + i] += 2
    adj[left].append((l + i, True))
    adj[right].append((l + i, False))
    out_deg[left] += 1
    out_deg[right] += 1

q = []
for i in range(l + p):
    if in_deg[i] == 0:
        p_success[i] = 1
        q.append(i)

for curr in q:
    for nx, is_left in adj[curr]:
        in_deg[nx] -= 1
        p_success[nx] += p_success[curr] * (probs[nx][0] if is_left else probs[nx][1])
        expected_value[nx] += expected_value[curr] * (probs[nx][0] if is_left else probs[nx][1])
        if in_deg[nx] == 0:
            q.append(nx)

tops = []
for i in range(l + p):
    if out_deg[i] == 0:
        tops.append(i)

print(max(expected_value[t] / p_success[t] for t in tops))
