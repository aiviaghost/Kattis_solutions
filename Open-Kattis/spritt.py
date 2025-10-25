n, s = map(int, input().split())
print("Jebb" if s >= sum(int(input()) for _ in range(n)) else "Neibb")
