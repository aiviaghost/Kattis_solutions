n = int(input())

out = []
x = 1
while x <= n:
    out.append(x)
    x *= 2

print(len(out))
print(" ".join(map(str, out)))
