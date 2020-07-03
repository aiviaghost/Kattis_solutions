n = int(input())

s = [i for i in input().split(" ")]

last_word = 0

for i in s:
    if(i == "mumble"):
        last_word += 1
    elif(int(i) - last_word != 1):
        break
    else:
        last_word = int(i)

print("makes sense" if last_word == n else "something is fishy")
