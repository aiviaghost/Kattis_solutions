print("Gnomes:")
for _ in range(int(input())):
    seq = list(map(int, input().split()))

    if seq == sorted(seq) or seq == sorted(seq, reverse=True):
        print("Ordered")
    else:
        print("Unordered")
