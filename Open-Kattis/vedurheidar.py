v = int(input())
n = int(input())

for _ in range(n):
    name, k = input().split()
    k = int(k)
    print(f'{name} {"lokud" if k < v else "opin"}')
