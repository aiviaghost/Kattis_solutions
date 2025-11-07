input()
left = sum(map(int, input().split()))
right = sum(map(int, input().split()))
print("left" if left < right else "either" if left == right else "right")
