target = set(input())

perm = input()

wrong = 0
correct = 0
i = 0

while correct < len(target) and wrong < 10:
    if perm[i] in target:
        correct += 1
    else:
        wrong += 1
    i += 1

if correct == len(target):
    print("WIN")
else:
    print("LOSE")
