n = int(input())
word = input()

for i in range(n, 0, -1):
    if(i == 1):
        print(str(i) + " bottle of " + word + " on the wall, " + str(i) + " bottle of " + word + ".")
        print("Take it down, pass it around, no more bottles of " + word + ".")
    else:
        print(str(i) + " bottles of " + word + " on the wall, " + str(i) + " bottles of " + word + ".")
        print("Take one down, pass it around, " + str(i - 1) + " bottles of " + word + " on the wall." if (i - 1) > 1 else "Take one down, pass it around, " + str(i - 1) + " bottle of " + word + " on the wall.")
        print("")
