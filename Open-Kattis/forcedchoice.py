n, p, s = map(int, input().split())

for _ in range(s):
    chosen = list(map(int, input().split()))[1:]
    if p in chosen:
        print("KEEP")
    else:
        print("REMOVE")
