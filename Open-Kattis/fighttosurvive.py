from collections import defaultdict

s, m = map(int, input().split())

hs = [(h, i) for i, h in enumerate(map(int, input().split()))]
starting_hs = {i : h for h, i in hs}

e = int(input())

ward = []
zombies = []
fail = False
resting = defaultdict(list)

for ei in range(1, e + 1):
    event = input()
    if fail:
        continue

    if ei in resting:
        hs.extend(resting.pop(ei))

    if ei % m == 0 and len(ward) > 0:
        ward.sort(key=lambda x: starting_hs[x])
        healed = ward.pop()
        new_h = starting_hs[healed] // 2
        if new_h > 0:
            hs.append((new_h, healed))
        else:
            ward.append(healed)
    
    hs.sort(key=lambda x: (x[0], starting_hs[x[1]]))

    approach = False
    if " " in event:
        approach = True
        _, z = event.split()
        z = int(z)
    
    if approach:
        zombies.append(z)
        continue

 
    zombie = zombies.pop(0)
    while zombie > 0:
        if len(hs) == 0:
            fail = True
            break

        h, attacker = hs.pop()

        if h >= zombie:
            h -= zombie
            zombie = 0
            if h > 0:
                resting[ei + 2].append((h, attacker))
            else:
                ward.append(attacker)
        else:
            ward.append(attacker)
            zombie -= h
        

if fail:
    print("overrun")
else:
    print("success")
