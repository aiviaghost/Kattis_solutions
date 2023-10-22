from math import gcd
from functools import reduce

def to_base_3(num):
    res = []
    while num:
        res.append(num % 3)
        num //= 3
    return "".join(map(str, res[::-1]))

for nums in map(lambda s: list(map(ord, s)), input().split()):
    key = reduce(gcd, nums)
    print(key)
    print(" ".join(to_base_3(i // key) for i in nums))
