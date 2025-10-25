a, b, c = (int(input()) for _ in range(3))

if a * c * 4 > b ** 2:
    print(0)
elif b ** 2 == 4 * c * a:
    print(1)
else:
    print(2)
