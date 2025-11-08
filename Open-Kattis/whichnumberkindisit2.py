squares = {num ** 2 for num in range(1001)}
for _ in range(int(input())):
    n = int(input())
    out = []
    if n & 1:
        out.append("O")
    if n in squares:
        out.append("S")
    if not out:
        out.append("EMPTY")
    print(*out, sep="")
