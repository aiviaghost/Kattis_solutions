from sys import stdin, stdout, setrecursionlimit; setrecursionlimit(int(2e5))
from math import gcd
from heapq import heapify, heappush, heappop
from functools import reduce
from itertools import permutations

INF = int(1e20)

def fac(n):
	return reduce(lambda x, y: x * y, range(1, n + 1))

for line in stdin:
	line = line.strip()
	seen = {}
	for c in line:
		if c in seen:
			seen[c] += 1
		else:
			seen[c] = 1
	ans = fac(len(line)) // reduce(lambda x, y: x * y, (fac(i) for i in seen.values()))
	stdout.write(str(ans) + "\n")
