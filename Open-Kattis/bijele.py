target = [1, 1, 2, 2, 2, 8]
print(" ".join(str(t - g) for t, g in zip(target, map(int, input().split()))))
