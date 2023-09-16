MOD = 10 ** 6

def mul(a, b):
    a[0][0], a[0][1], a[1][0], a[1][1] = (
         (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD, 
         (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD, 
         (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD, 
         (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD
    )

def bin_exp(base, exp):
    res = [[1, 0], [0, 1]]
    while exp:
        if exp & 1:
            mul(res, base)
        mul(base, base)
        exp >>= 1
    return res

n = int(input())

m = [[0, 1], [1, 1]]

print(bin_exp(m, n)[1][1])
