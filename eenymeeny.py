song = len(input().split()) - 1

n = int(input())

people = list()
for _ in range(n):
    people.append(input())

g1, g2 = [], []
it = 0
curr = 0
while (people):
    curr = (curr + song) % len(people)
    if it % 2 == 0:
        g1.append(people[curr])
    else:
        g2.append(people[curr])
    del people[curr]
    it += 1

print(len(g1))
for p in g1:
    print(p)

print(len(g2))
for p in g2:
    print(p)
