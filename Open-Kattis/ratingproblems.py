def mean(xs):
    return sum(xs) / len(xs)

n, k = map(int, input().split())

given = [int(input()) for _ in range(k)]

print(mean(given + [-3] * (n - k)), mean(given + [3] * (n - k)))
