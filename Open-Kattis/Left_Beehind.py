from sys import stdin, stdout

while True:
    x, y = map(int, stdin.readline().split())
    if x == y == 0:
        exit()
    elif x + y == 13:
        stdout.write("Never speak again.\n")
    elif x > y:
        stdout.write("To the convention.\n")
    elif x < y:
        stdout.write("Left beehind.\n")
    elif x == y:
        stdout.write("Undecided.\n")
