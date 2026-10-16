from bisect import bisect

n = int(input())

nums = sorted(int(input()) for _ in range(n))

ans = 0
for i in range(n):
    for j in range(i + 1, n):
        max = nums[i] + nums[j]
        end = bisect(nums, max - 1, j, n)
        range_len = end - j - 1
        ans += 2**range_len - 1

print(ans)
