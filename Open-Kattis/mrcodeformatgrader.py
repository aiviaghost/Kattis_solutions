c, n = map(int, input().split())

ns = list(map(int, input().split()))

in_n = set(ns)

correct = [i for i in range(1, c + 1) if i not in in_n]

def f(xs):
    outs = []
    i = 0
    while i < len(xs):
        j = i + 1
        if j < len(xs) and xs[j] - xs[j - 1] == 1:
            while j < len(xs) and xs[j] - xs[j - 1] == 1:
                j += 1
            outs.append([xs[i], xs[j - 1]])
        else:
            outs.append([xs[i]])
        i = j
    ret = [f"{ab[0]}-{ab[1]}" if len(ab) == 2 else f"{ab[0]}" for ab in outs]
    if len(ret) < 2:
        return ret[0]
    else:
        return ", ".join(ret[:-1]) + " and " + ret[-1]
print(f"Errors: {f(ns)}")
print(f"Correct: {f(correct)}")
