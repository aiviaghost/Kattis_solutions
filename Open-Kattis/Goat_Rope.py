from math import sqrt

x, y, x1, y1, x2, y2 = map(int, input().split())

def dist(x, y, xp, yp):
    return sqrt((x - xp) ** 2 + (y - yp) ** 2)

if y1 < y < y2 and x < x1:
    print(dist(x, y, x1, y))
elif y1 < y < y2 and x > x2:
    print(dist(x, y, x2, y))
elif x1 < x < x2 and y < y1:
    print(dist(x, y, x, y1))
elif x1 < x < x2 and y > y2:
    print(dist(x, y, x, y2))
else:
    print(min([dist(x, y, p[0], p[1]) for p in [(x1, y1), (x1, y2), (x2, y1), (x2, y2)]]))
