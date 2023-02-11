n = int(input())

control = []
other = []

for _ in range(n):
    line = input()
    if line[0] == 'N':
        control.append(line[1:])
    else:
        other.append(line[1:])

abc_c = [0] * 3
abc = [0] * 3

for i in control:
    for j in range(3):
        if i[j] == 'Y':
            abc_c[j] += 1

for i in other:
    for j in range(3):
        if i[j] == 'Y':
            abc[j] += 1

for i in range(3):
    abc_c[i] /= len(control)
    abc[i] /= len(other)

for i in range(3):
    if abc[i] >= abc_c[i]:
        print("Not Effective")
    else:
        print(100.0 * (1 - abc[i] / abc_c[i]))
