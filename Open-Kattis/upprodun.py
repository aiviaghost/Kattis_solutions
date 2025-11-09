n = int(input())
m = int(input())

left = m
div = m // n
mod = m % n
for _ in range(n):
    print("*" * (div + (mod > 0)))
    mod -= 1
