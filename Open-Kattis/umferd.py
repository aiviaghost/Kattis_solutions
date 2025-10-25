from sys import stdin
from collections import Counter

counts = Counter("".join(stdin.readlines()))

print(counts["."] / (counts["."] + counts["#"]))
