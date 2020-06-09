from sys import stdin, stdout

for line in stdin:
    a, b = map(int, line.split())
    stdout.write(str(abs(a - b)))
    stdout.write("\n")
