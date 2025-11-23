for _ in range(int(input())):
    s = input()
    print("YES" if all(c in s for c in input()) else "NO")
