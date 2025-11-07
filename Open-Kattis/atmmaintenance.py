K = int(input().split()[1])

print("".join((K := K - x, "1")[1] if x <= K else "0" for x in map(int, input().split())))
