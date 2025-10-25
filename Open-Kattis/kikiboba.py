s = input()

bs = sum(c == "b" for c in s)
ks = sum(c == "k" for c in s)

if bs == ks == 0:
    print("none")
elif bs > ks:
    print("boba")
elif ks > bs:
    print("kiki")
else:
    print("boki")
