N = int(input())

first = (N + 1) * N // 2
second = ((N * (N + 1) * (2 * N + 1) // 6) + first) // 2

print(first, second, sep="\n")
