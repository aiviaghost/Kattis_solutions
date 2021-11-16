from math import sqrt

n = int(input())

def ask(x, y):
	global n
	print(f"{x} {y}", flush=True)
	dist = int(input())
	if dist == 0:
		n -= 1
	if n == 0:
		exit(0)	
	return dist

while n > 0:
	lb, rb = 0, int(1e6)
	while lb < rb:
		r = rb - lb
		b1 = lb + (r // 3)
		b2 = rb - (r // 3)
		a1 = ask(0, b1)
		a2 = ask(0, b2)
		if a1 <= a2:
			rb = b2 - 1
		else:
			lb = b1 + 1
	xd = ask(0, lb)
	ask(round(sqrt(xd)), lb)
