from sys import stdin

inp = (line for line in stdin.read().strip().split("\n"))

cas = 1
for line in inp:
    xs = line.split()[1:]
    xs = list(map(int, xs))
    print(f"Case {cas}:", min(xs), max(xs), max(xs) - min(xs))
    cas += 1
