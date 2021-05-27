from sys import stdin, stdout

zero = ["+---+", "|   |","|   |","+   +","|   |","|   |","+---+"]

one = ["    +","    |","    |","    +","    |", "    |","    +"]

two = ["+---+","    |","    |","+---+","|    ","|    ","+---+"]

three = ["+---+","    |","    |","+---+","    |","    |","+---+"]

four = ["+   +","|   |", "|   |", "+---+", "    |", "    |", "    +"]

five = ["+---+", "|    ", "|    ", "+---+", "    |", "    |", "+---+"]

six = ["+---+", "|    ", "|    ", "+---+", "|   |", "|   |","+---+"]

seven = ["+---+", "    |", "    |", "    +", "    |", "    |", "    +"]

eight = ["+---+", "|   |", "|   |", "+---+", "|   |", "|   |", "+---+"]

nine = ["+---+", "|   |", "|   |", "+---+", "    |", "    |", "+---+"]

d = {0 : zero, 1 : one, 2 : two, 3 : three, 4 : four, 5 : five, 6 : six, 7 : seven, 8 : eight, 9 : nine}

while True:
    t = stdin.readline().rstrip()
    if(t == "end"):
        stdout.write("end\n")
        break
    else:
        t = [int(i) for i in t if i != ":"]
    
    for i in range(7):
        out = ""
        out += d[t[0]][i]
        out += "  "
        out += d[t[1]][i]
        if i == 2 or i == 4:
            out += "  o  "
        else:
            out += "     "
        out += d[t[2]][i]
        out += "  "
        out += d[t[3]][i]
        out += "\n"
        stdout.write(out)

    stdout.write("\n\n")
