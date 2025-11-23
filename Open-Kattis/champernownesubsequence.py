from collections import deque
input()
n = deque(input())
k = 0
while n:
    k += 1
    seq = deque(str(k))
    while seq and n:
        if seq[0] == n[0]:
            n.popleft()
        seq.popleft()
print(k)
