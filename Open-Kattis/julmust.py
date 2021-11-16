R = int(input())

lb, rb = 1, R

for day in range(1, 86):
    mid = (lb + rb) // 2
    print(mid * day, flush=True)
    res = input()
    if res == "exact":
        exit()
    elif res == "less":
        rb = mid - 1
    else:
        lb = mid + 1
