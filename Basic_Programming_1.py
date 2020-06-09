from sys import stdin, stdout
from string import ascii_lowercase

N, t = map(int, stdin.readline().split())

A = [int(i) for i in stdin.readline().split()]

if t == 1:
    stdout.write("7")

elif t == 2:
    if A[0] > A[1]:
        stdout.write("Bigger")
    elif A[0] == A[1]:
        stdout.write("Equal")
    elif A[0] < A[1]:
        stdout.write("Smaller")

elif t == 3:
    stdout.write(str(sorted(A[0 : 3])[1]))

elif t == 4:
    stdout.write(str(sum(A)))

elif t == 5:
    stdout.write(str(sum([i for i in A if (i & 1) == 0])))

elif t == 6:
    stdout.write("".join([ascii_lowercase[i % 26] for i in A]))

elif t == 7:
    counter = 0
    i = 0
    while True:
        i = A[i]
        
        if i > N - 1:
            stdout.write("Out")
            exit()

        if counter > N:
            stdout.write("Cyclic")
            exit()

        if i == N - 1:
            stdout.write("Done")
            exit()

        counter += 1
