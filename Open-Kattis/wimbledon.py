n = int(input())

a, b = map(list, zip(*(map(int, input().split()) for _ in range(n))))

suff = [0] * n
for i in range(n - 2, -1, -1):
    suff[i] = suff[i + 1] + a[i + 1]
all_pairs = sum(a[i] * suff[i] for i in range(n))

sum_a = sum(a)
ans = sum(b[i] * (all_pairs - a[i] * (sum_a - a[i])) for i in range(n))

print(ans)
