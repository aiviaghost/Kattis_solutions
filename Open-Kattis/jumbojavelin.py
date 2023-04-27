from functools import reduce

n = int(input())
lens = [int(input()) for _ in range(n)]

print(reduce(lambda acc, curr: acc + curr - 1, lens))
