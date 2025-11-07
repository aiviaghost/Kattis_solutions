scores = [0, 0]
win_by_two = False

s = input()
for player, points in zip(s[::2], s[1::2]):
    win_by_two |= scores[0] == scores[1] == 10
    scores[player != "A"] += int(points)

if (scores[0] >= 11 and not win_by_two) or (win_by_two and scores[0] >= scores[1] + 2):
    print("A")
else:
    print("B")
