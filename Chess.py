from sys import stdin, stdout

letter_to_int = {"A" : 0, "B" : 1, "C" : 2, "D" : 3, "E" : 4, "F" : 5, "G" : 6, "H" : 7}
int_to_letter = {0 : "A", 1 : "B", 2 : "C", 3 : "D", 4 : "E", 5 : "F", 6 : "G", 7 : "H"}

def convert_input(char):
    if char in "123456789":
        return int(char) - 1
    else:
        return letter_to_int[char]

neighbours = []
for i in range(1, 8):
    neighbours.append((i, i))
    neighbours.append((-i, i))
    neighbours.append((i, -i))
    neighbours.append((-i, -i))

T = int(stdin.readline())
for _ in range(T):
    x1, y1, x2, y2 = map(convert_input, stdin.readline().rstrip().split())

    # bfs
    vis = [[-1] * 8 for _ in range(8)]
    vis[y1][x1] = 1
    parents = [[()] * 8 for _ in range(8)]
    parents[y1][x1] = (x1, y1)

    curr_layer = [(x1, y1)]

    while curr_layer:
        next_layer = []
        for c in curr_layer:
            for n in neighbours:
                nx = c[0] + n[0]
                ny = c[1] + n[1]
                if 0 <= nx < 8 and 0 <= ny < 8 and vis[ny][nx] == -1:
                    vis[ny][nx] = 1
                    next_layer.append((nx, ny))
                    parents[ny][nx] = (c[0], c[1])
        curr_layer = next_layer

    if vis[y2][x2] == -1:
        stdout.write("Impossible" + "\n")
    else:
        path = []
        path.append((x2, y2))
        px, py = x2, y2
        while px != x1 or py != y1:
            px, py = parents[py][px]
            path.append((px, py))
        
        out = ""
        out += str(len(path) - 1)
        for i in range(len(path) - 1, -1, -1):
            out += " " + int_to_letter[path[i][0]] + " " + str(path[i][1] + 1)
        
        stdout.write(out + "\n")
