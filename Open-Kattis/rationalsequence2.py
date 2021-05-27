from sys import stdin, stdout

def get_N(p, q):
    if p == q == 1:
        return 1
    elif p < q:
        return 2 * get_N(p, q - p)
    else:
        return 2 * get_N(p - q, q) + 1

P = int(stdin.readline())
for _ in range(P):
    K, PQ = stdin.readline().split()
    p, q = map(int, PQ.split("/"))
    N = get_N(p, q)
    stdout.write(K + " " + str(N) + "\n")
