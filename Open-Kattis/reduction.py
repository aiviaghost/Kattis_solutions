from sys import stdin, stdout
import re


costs = [0] * 100001

def solve(N, M, A, B):
    costs[N] = 0
    closest = N
    prev = N
    i = N
    while i > 0:
        costs[i] = costs[prev] + min(A * (prev - i), B)
        prev = i
        if i >= M:
            closest = i
        i //= 2
    return costs[closest] + A * (closest - M)

T = int(stdin.readline())
for t in range(1, T + 1):
    N, M, L = map(int, stdin.readline().split())
    sorted_table = []
    for _ in range(L):
        name, a, b = re.compile("[:,]").split(stdin.readline())
        A = int(a)
        B = int(b)
        sorted_table.append((solve(N, M, A, B), name))
    sorted_table.sort()
    stdout.write("Case " + str(t) + "\n")
    for cost, name in sorted_table:
        stdout.write(name + " " + str(cost) + "\n")
