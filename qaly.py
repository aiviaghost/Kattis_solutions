n = int(input())

sum = 0.0
for i in range(n):
    a, b = [float(i) for i in input().split(" ")]
    sum += a * b

print(sum)