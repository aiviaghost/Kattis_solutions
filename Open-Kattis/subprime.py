def sieve(n):
    is_prime = [True] * (n + 1)
    i = 2
    while i * i <= n:
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
        i += 1
    return [i for i in range(2, n + 1) if is_prime[i]]

primes = sieve(1300000)

l, h = map(int, input().split())
p = input()

count = 0
for prime in map(str, primes[l - 1 : h]):
    if p in prime:
        count += 1
print(count)
