_, target = map(int, input().split())

idx = list(map(int, input().split())).index(target)

print("fyrst" if idx == 0 else "naestfyrst" if idx == 1 else f"{idx + 1} fyrst")
