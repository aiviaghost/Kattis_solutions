for _ in range(int(input())):
    s = input().split()
    print("YES" if any(c in s[:i] + s[i + 1:] for i, c in enumerate(input().split())) else "NO")
