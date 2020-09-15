from sys import stdin, stdout

def get_pq(N):
    if N == 1:
        return 1, 1
    else:
        p, q = get_pq(N // 2)
        if (N & 1) == 0:
            return p, p + q
        else:
            return p + q, q
        
P = int(stdin.readline())
for _ in range(P):
    K, N = map(int, stdin.readline().split())
    p, q = get_pq(N)
    stdout.write(str(K) + " " + str(p) + "/" + str(q) + "\n")
