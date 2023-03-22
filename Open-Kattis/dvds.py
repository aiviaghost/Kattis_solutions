for _ in range(int(input())):
    input()
    xs = list(map(int, input().split()))
    ans = 0
    target = 1
    for i in xs:
        if i != target:
            ans += 1
        else:
            target += 1
    print(ans)
