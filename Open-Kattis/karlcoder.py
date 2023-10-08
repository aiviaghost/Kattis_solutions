lb, rb = 1, 2
while 1:
    print(f"buf[{rb}]", flush=True)
    if int(input()) == 0:
        break
    lb = rb
    rb *= 2

while rb - lb > 1:
    mid = (lb + rb) // 2
    print(f"buf[{mid}]", flush=True)
    if int(input()) == 0:
        rb = mid
    else:
        lb = mid

print(f"strlen(buf) = {lb + 1}")
