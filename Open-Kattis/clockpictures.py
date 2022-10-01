from functools import reduce

B = 360000
P = 10 ** 16 + 61

def hash(s):
    return reduce(lambda poly, coeff: (poly * B + coeff) % P, s)

n = int(input())
a, b = sorted(map(int, input().split())), sorted(map(int, input().split()))

# Modulo operators in other languages might return negative results which might be unwanted. If so add the base (B) before mod.
# ad, bd = [(a[(i + 1) % n] - a[i] + B) % B for i in range(n)], [(b[(i + 1) % n] - b[i] + B) % B for i in range(n)]
ad, bd = [(a[(i + 1) % n] - a[i]) % B for i in range(n)], [(b[(i + 1) % n] - b[i]) % B for i in range(n)]

ha, hb = hash(ad), hash(bd)
ok = ha == hb
if not ok:
    for i in range(n):
        hb = (hb * B - bd[i] * pow(B, n, P) + bd[i]) % P # might require similar trick as above in other languages.
        if ha == hb:
            ok = True
            break

print("possible" if ok else "impossible")
