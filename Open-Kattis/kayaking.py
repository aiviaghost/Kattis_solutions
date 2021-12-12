from sys import stdin, stdout, setrecursionlimit; setrecursionlimit(200000)
from math import gcd, sqrt
from heapq import heapify, heappush, heappop
from functools import reduce
from itertools import permutations, product

INF = int(1e20)

b, n, e = map(int, input().split())
sb, sn, se = map(int, input().split())
kayaks = sorted(map(int, input().split()))

options = sorted((
	(2 * sb, (0, 0)), 
	(sb + sn, (0, 1)), 
	(sb + se, (0, 2)), 
	(2 * sn, (1, 1)), 
	(sn + se, (1, 2)), 
	(2 * se, (2, 2))
))

def valid(target):
	available = [b, n, e]
	for c in kayaks:
		worked = False
		for strength, (p1, p2) in options:
			if strength * c >= target:
				if (p1 == p2 and available[p1] >= 2) or (p1 != p2 and available[p1] >= 1 and available[p2] >= 1):
					available[p1] -= 1
					available[p2] -= 1
					worked = True
					break
		if not worked:
			return False
	return True

lb = 0
rb = INF
while lb < rb:
	mid = (lb + rb + 1) // 2
	if valid(mid):
		lb = mid
	else:
		rb = mid - 1

print(lb)
