MOD = 10 ** 9 + 7

def choose(n, k):
    combinations = 1
    if k < n - k:
        k = n - k
    for i in range(k):
        combinations = (combinations * (n - i)) % MOD
        combinations = (combinations * pow(i + 1, -1, MOD)) % MOD
    return combinations

n, m = map(int, input().split())

if n <= m:
    print(choose(m, n))
else:
    print(choose(n - 1, m - 1))
