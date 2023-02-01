INF = 10 ** 20

ns = input()
n = int(ns)

if all(c in ns for c in "0123456789"):
    print("Impossible")
    exit(0)

not_in_n = [int(c) for c in "0123456789" if c not in ns]

def f(b):
    return [x for x in not_in_n if x < b]

def lower_bound():
    poss = [0] * len(ns)
    bi = f(int(ns[0]))
    poss[0] = str(max(bi)) if len(bi) > 0 else "0"
    m = max(not_in_n)
    for i in range(1, len(ns)):
        poss[i] = str(m)
    res = int("".join(poss))
    return res if res < n else -INF

def f2(b):
    return [x for x in not_in_n if x > b]

nonzero = [int(c) for c in "123456789" if c not in ns]

def upper_bound():
    bi = f2(int(ns[0]))
    size = len(ns)
    poss = [0] * size
    if len(bi) == 0:
        size += 1
        poss.append(0)
        poss[0] = str(min(nonzero)) if len(nonzero) > 0 else "0"
    else:
        poss[0] = str(min(bi))
    mi = min(not_in_n)
    for i in range(1, size):
        poss[i] = str(mi)
    res = int("".join(poss))
    return res if res > n else INF

lb = lower_bound()
ub = upper_bound()

if abs(lb - n) == abs(ub - n):
    print(lb, ub)
elif abs(lb - n) < abs(ub - n):
    print(lb)
else:
    print(ub)
