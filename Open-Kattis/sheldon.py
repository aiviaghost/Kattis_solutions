X, Y = map(int, input().split())

nums = set()

for n in range(1, 64):
    for m in range(1, 63):
        for k in range(1, 64):
            num = "".join("1" * n if i % 2 == 0 else "0" * m for i in range(k))
            if len(num) >= 64:
                break
            num = int(num, 2)
            if X <= num <= Y:
                nums.add(num)

print(len(nums))
