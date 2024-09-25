s = input()

alive = ":)" in s
dead = ":(" in s

if alive and not dead:
    print("alive")
elif not alive and dead:
    print("undead")
elif alive and dead:
    print("double agent")
else:
    print("machine")