from collections import defaultdict

probs = defaultdict(int)
for i in range(1, 7):
    for j in range(1, 7):
        probs[i + j] += 1
probs = {s : c / 36 for s, c in probs.items()}

input()
print(sum(probs[x] for x in map(int, input().split())))
