inp = input().split("+")

n = len(inp) - 1

possible = set()

for bits in range(1 << n):
    mask = [(bits >> i) & 1 for i in range(n)]
    xs = []
    i = 0
    while i < n:
        if mask[i] == 0:
            xs.append(inp[i])
            i += 1
        else:
            j = i + 1
            while j < n:
                if mask[j] == 1:
                    j += 1
                else:
                    break
            xs.append("".join(inp[i : j + 1]))
            i = j + 1
    while i <= n:
        xs.append(inp[i])
        i += 1
    possible.add(sum(int(i) for i in xs))

print(len(possible))
