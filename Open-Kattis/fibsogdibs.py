MOD = 10 ** 9 + 7

def vector_mul(mat, vec):
    return [
        (mat[0][0] * vec[0] + mat[0][1] * vec[1]) % MOD,
        (mat[1][0] * vec[0] + mat[1][1] * vec[1]) % MOD
    ]

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

start = [*map(int, input().split())]
ans = vector_mul(bin_exp([[0, 1], [1, 1]], 2 * int(input())), start)

print(*ans)
