input()

abc = "abcdefghijklmnopqrstuvwxyz"
qwerty = "qwertyuiopasdfghjklzxcvbnm"

abc_to_qwerty = dict(zip(abc, qwerty))

print("".join(abc_to_qwerty.get(c, " ") for c in input()))
