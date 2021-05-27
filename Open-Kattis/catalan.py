from sys import stdin, stdout


d = {0 : 1, 1 : 1}

def get_catalan_number(x):
    n = d[len(d) - 1]
    for i in range(len(d), x + 1):
        n = (((i << 2) - 2) * n) // (i + 1)
        d[i] = n
    return d[x]


n = int(stdin.readline())

for _ in range(n):
    stdout.write(str(get_catalan_number(int(stdin.readline()))))
    stdout.write("\n")
