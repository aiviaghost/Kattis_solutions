from sys import stdin, stdout, setrecursionlimit; setrecursionlimit(200000)
from math import gcd, sqrt
from heapq import heapify, heappush, heappop
from functools import reduce
from itertools import permutations, product

INF = int(1e20)

"""

ext_euc gives s, t s.t s * n + t * m = 1

we want to find: 
	x = a (mod n)
	x = b (mod m)

x = a * m * k1 + b * n * k2

a * m * k1 + b * n * k2 = a * m * k1 (mod n)
a * m * k1 + b * n * k2 = b * n * k2 (mod m)

let k1 = pow(m, -1, n), k2 = pow(n, -1, m)

s * n + t * m = !
s * n - 1 = - t * m
s * n - 1 = 0 (mod m)
s * n = 1 (mod m)

s * n + t * m = !
t * m - 1 = -s * n
t * m - 1 = 0 (mod n)
t * m = 1 (mod n)

"""

def ext_euc(n, m):
	old_r, r = n, m
	old_s, s = 1, 0
	old_t, t = 0, 1
	while r != 0:
		q = old_r // r
		old_r, r = r, old_r - q * r
		old_s, s = s, old_s - q * s
		old_t, t = t, old_t - q * t
	return old_s, old_t

for _ in range(int(input())):
	a, n, b, m = map(int, input().split())
	s, t = ext_euc(n, m)
	x = a * m * t + b * n * s
	K = n * m
	print(x % K, K)
