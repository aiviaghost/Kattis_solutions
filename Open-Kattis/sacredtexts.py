from sys import stdin

d = {c : i for i, c in enumerate("""!"#$%&'()*+,-./""", start = 1)}

al = [chr(i) for i in range(ord("a"), ord("z") + 1)]

def conv(s):
    return sum(d[c] for c in s)

x, c = next(stdin).split()
x = conv(x)
while al[x - 1] != c:
    al = [al[-1]] + al[:-1]

for line in stdin:
    sol = []
    for word in line.split():
        if word == "0":
            sol.append(" ")
        elif word == "<":
            sol.append(",")
        elif word == ">":
            sol.append(".")
        else:
            sol.append(al[conv(word) - 1])
    print("".join(sol))
