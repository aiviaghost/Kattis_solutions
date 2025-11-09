from collections import Counter

print(*(f"{place} {count}" for place, count in Counter((input(), input())[1] for _ in range(int(input()))).items()), sep="\n")
