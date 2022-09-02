class Score:
    def __init__(self, a, b):
        self.a = a
        self.b = b
    def __gt__(self, other):
        return self.a > other.a or self.a == other.a and self.b < other.b
buffer = []
lower, higher = {}, {}
n, m = map(int, input().split())
curr = Score(0, 0)
for _ in range(m):
    t, p = map(int, input().split())
    if t == 1:
        curr = Score(curr.a + 1, curr.b + p)
        delete = []
        for k, v in higher.items():
            if not v > curr:
                delete.append(k)
        for k in delete:
            lower[k] = higher[k]
            del higher[k]
    else:
        if t not in lower and t not in higher:
            ns = Score(1, p)
            if not ns > curr:
                lower[t] = ns
            else:
                higher[t] = ns
        elif t in lower:
            ps, pp = lower[t].a, lower[t].b
            ns = Score(ps + 1, pp + p)
            if ns > curr:
                del lower[t]
                higher[t] = ns
            else:
                lower[t] = ns
        else:
            ps, pp = higher[t].a, higher[t].b
            ns = Score(ps + 1, pp + p)
            higher[t] = ns
    buffer.append(len(higher) + 1)
print("\n".join(map(str, buffer)))
