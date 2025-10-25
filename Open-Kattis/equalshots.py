a, b = map(int, input().split())

a1 = sum(int.__mul__(*map(int, input().split())) for _ in range(a))
a2 = sum(int.__mul__(*map(int, input().split())) for _ in range(b))

print("same" if a1 == a2 else "different")
