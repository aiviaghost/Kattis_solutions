text = input()

smileys = [":)", ";)", ":-)", ";-)"]

found = []

for i in range(len(text)):
    if (i + 2 <= len(text) and text[i : i + 2] in smileys):
        found.append(i)
    elif (i + 3 <= len(text) and text[i : i + 3] in smileys):
        found.append(i)

for i in found:
    print(i)
