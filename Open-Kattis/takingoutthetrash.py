n, m = map(int, input().split())

nums = sorted(map(int, input().split()))
ans = 0
l, r = 0, n - 1
while l <= r:
    ans += 1
    if nums[l] + nums[r] <= m:
        l += 1
    r -= 1

print(ans)
