from sys import stdin, stdout


for t in range(int(stdin.readline())):
    if t > 0:
        stdout.write("\n")
    params = [int(i) for i in stdin.readline().rstrip().split()]
    A, B = params[:-2:2], params[1:-2:2]
    c, d = params[-2], params[-1]
    dp = [[c] * 100 for _ in range(100)]
    for i in range(100):
        dp[0][i] = dp[i][0] = d
    for i in range(1, 100):
        for j in range(1, 100):
            for a, b in zip(A, B):
                if i >= a and j >= b:
                    dp[i][j] += dp[i - a][j - b]
                else:
                    dp[i][j] += d
    xys = [int(i) for i in stdin.readline().rstrip().split()]
    for x, y in zip(xys[::2], xys[1::2]):
        stdout.write(str(dp[x][y]) + "\n")
