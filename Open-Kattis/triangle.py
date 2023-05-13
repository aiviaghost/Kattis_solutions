from sys import stdin

cas = 1
for line in stdin.read().strip().split("\n"):
    n = int(line)
    print(f"Case {cas}:", len(str(3 ** (n + 1) // 2 ** n)))
    cas += 1