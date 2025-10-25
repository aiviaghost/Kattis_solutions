s = 0
for i in range(2 * int(input())):
    x = input()
    if i % 2 == 1:
        s += int(x)

print("Usch, vinst" if s > 0 else "Lagom" if s == 0 else "Nekad")
