from sys import stdin, stdout

def is_prime(x):
	i = 2
	while i * i <= x:
		if x % i == 0:
			return False
		i += 1
	return True

def is_number(x):
	return x[0] != "0" and all(i in "0123456789" for i in x)

lines = []

for line in stdin:
	lines.append(line.strip())

parts = " ".join(lines).split()

if len(parts) != 3 or not all(is_number(i) for i in parts):
	stdout.write("0\n")
	exit(0)

a, b, c = map(int, parts)

if a % 2 == 1 or a <= 3 or a > int(1e9):
	stdout.write("0\n")
	exit(0)

if is_prime(b) and is_prime(c) and a == b + c:
	stdout.write("1\n")
else:
	stdout.write("0\n")
