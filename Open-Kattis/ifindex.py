depths = []
curr_depth = 0
for c in input():
    if c == "{":
        curr_depth += 1
    elif c == "}":
        curr_depth -= 1
    elif c == "i":
        depths.append(curr_depth)

ans = sorted(depths)[(len(depths) + 1) // 2 - 1] if depths else -1

print(ans)
