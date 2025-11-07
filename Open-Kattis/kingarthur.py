from math import pi

d, w, n = (float(input()) for _ in range(3))

print("YES" if n * w <= pi * d else "NO")
