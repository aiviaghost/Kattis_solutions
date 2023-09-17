from collections import defaultdict

MOD = 998_244_353

N, t = map(int, input().split())

MAX_DIGITS = len(bin(N)[2:]) + 1

pows = [2 ** i for i in range(MAX_DIGITS)]

dp = defaultdict(lambda: [-1] * (MAX_DIGITS + 1))

def solve(target, num_digits):
    if num_digits == 0:
        return target == 0

    if t * (2 ** num_digits - 1) < target:
        return 0

    if dp[target][num_digits] != -1:
        return dp[target][num_digits]

    res = 0
    for digit in range(t + 1):
        if digit * pows[num_digits - 1] <= target and num_digits - 1 >= 0:
            res = (res + solve(target - digit * pows[num_digits - 1], num_digits - 1)) % MOD

    dp[target][num_digits] = res
    return res

print(solve(N, MAX_DIGITS))
