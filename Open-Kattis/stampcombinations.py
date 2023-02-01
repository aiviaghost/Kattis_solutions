m, n = map(int, input().split())

stamps = list(map(int, input().split()))

prefix = [0] * m
prefix[0] = stamps[0]
for i in range(1, m):
    prefix[i] = prefix[i - 1] + stamps[i]

def query(x):
    seen = set()
    last_suffix = 0
    for i in range(m - 1, -1, -1):
        if prefix[i] == x:
            return True
        if prefix[i] < x and (x - prefix[i]) in seen:
            return True
        if last_suffix == x:
            return True
        last_suffix = last_suffix + stamps[i]
        seen.add(last_suffix)
    return False

for _ in range(n):
    print("Yes" if query(int(input())) else "No")
