from sys import stdin as cin, stdout as cout

d = {0 : 1, 1 : 1}

def get_catalan_number(x):
    n = d[len(d) - 1]
    for i in range(len(d), x + 1):
        n = (((i << 2) - 2) * n) // (i + 1)
        d[i] = n
    return d[x]

n = int(cin.readline())

get_catalan_number(n)

square = 0
for k in range(n + 1):
    square += d[k] * d[n - k]

cout.write(str(square))
