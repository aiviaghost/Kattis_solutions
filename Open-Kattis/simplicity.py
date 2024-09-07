from collections import Counter
print(sum(sorted(Counter(input()).values())[:-2]))