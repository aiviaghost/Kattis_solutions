R, _, Z_R, Z_C = map(int, input().split())

print("\n".join(row for inner in [[row] * Z_R for row in ["".join(c * Z_C for c in input()) for _ in range(R)]] for row in inner))
