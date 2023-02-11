inp = input().split("+")

n = len(inp) - 1

possible = set()

for ii in range(1 << n):
    bits = [(ii >> i) & 1 for i in range(n)]
    xs = []
    i = 0
    j = 0
    while i < n:
        if bits[i] == 0:
            xs.append(inp[i])
            i += 1
        else:
            j = i + 1
            while j < n:
                if bits[j] == 1:
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
