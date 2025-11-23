alph = dict(zip("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", range(62)))

def to_base_62(s):
    return list(map(alph.get, s))

def compare(l1, l2):
    if len(l1) != len(l2):
        return len(l1) < len(l2)
    return l1 < l2

for _ in range(int(input())):
    print("YES" if compare(*map(to_base_62, sorted([input(), input()]))) else "NO")
