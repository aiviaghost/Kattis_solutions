N = int(input())
M = int(input())

total_points = {problem : 0 for problem in input().split()}
for _ in range(M):
    for score, problem in zip(map(int, input().split()), total_points.keys()):
        total_points[problem] += score

print(max(total_points, key=total_points.get))
