input()
for x in map(int, input().split()):
    ans, prev = 0, 0
    for i in range(8):
        curr = (x & 1) ^ prev
        x >>= 1
        ans |= curr << i
        prev = curr
    print(ans)
