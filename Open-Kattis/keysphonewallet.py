items = {"keys","phone","wallet"}

for _ in range(int(input())):
    items.discard(input())

if items:
    print(*sorted(items), sep="\n")
else:
    print("ready")
