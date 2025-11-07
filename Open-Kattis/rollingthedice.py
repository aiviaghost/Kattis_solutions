import re

x, y, z = map(int, re.split("[d+]", input()))

print(z + x * (y + 1) / 2)
