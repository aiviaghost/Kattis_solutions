x_h, y_h = map(int, input().split())
x_p, y_p = map(int, input().split())
print(2 - (x_h == x_p or y_h == y_p))
