L, x = map(int, input().split())

ans = 0
on_terrace = 0
for _ in range(x):
    direction, group = input().split()
    group = int(group)
    if direction == "enter":
        if on_terrace + group > L:
            ans += 1
        else:
            on_terrace += group
    else:
        on_terrace -= group

print(ans)
