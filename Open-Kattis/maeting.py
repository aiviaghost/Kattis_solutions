n = int(input())

counts = {input() : 0 for _ in range(n)}

m = int(input())
for _ in range(m):
    for s in input().split()[1:]:
        counts[s] += 1

print("\n".join(f"{c} {s}" for c, s in sorted([(v, k) for k, v in counts.items()], reverse=True)))
