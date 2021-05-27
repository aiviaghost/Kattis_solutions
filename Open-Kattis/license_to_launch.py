n = int(input())

running_min = [1000000001, 0]

stats = [int(i) for i in input().split(" ")]
for i in range(n):
    if(running_min[0] > stats[i]):
        running_min[0] = stats[i]
        running_min[1] = i

print(running_min[1])
