for _ in range(int(input())):
    a = input()
    b = input()
    print(a)
    print(b)
    print("".join("*" if aa != bb else "." for aa, bb in zip(a, b)))
    print()
