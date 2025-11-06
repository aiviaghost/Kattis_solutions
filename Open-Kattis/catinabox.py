from math import prod

*box_dims, cat = map(int, input().split())
vol = prod(box_dims)

print("SO MUCH SPACE" if cat < vol else "COZY" if vol == cat else "TOO TIGHT")
