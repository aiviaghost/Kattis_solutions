n, k = map(int, input().split())

print(min(k, len({int(input()) for _ in range(n)})))
