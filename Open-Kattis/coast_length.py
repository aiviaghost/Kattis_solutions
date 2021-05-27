from sys import stdin, stdout


def MakeSet(x):
     x.parent = x
     x.rank   = 0

def Union(x, y):
     xRoot = Find(x)
     yRoot = Find(y)
     if xRoot.rank > yRoot.rank:
         yRoot.parent = xRoot
     elif xRoot.rank < yRoot.rank:
         xRoot.parent = yRoot
     elif xRoot != yRoot: 
         yRoot.parent = xRoot
         xRoot.rank = xRoot.rank + 1

def Find(x):
     if x.parent == x:
        return x
     else:
        x.parent = Find(x.parent)
        return x.parent

class Node:
    def __init__ (self):
        self.visited = 0


n, m = map(int, stdin.readline().split())

grid = []
grid.append([0] * (m + 2))
for _ in range(n):
    grid.append([0] + [int(i) for i in stdin.readline().rstrip()] + [0])
grid.append([0] * (m + 2))


nodes = []
for y in range(n + 2):
    nodes.append([])
    for _ in range(m + 2):
        node = Node()
        nodes[y].append(node)
        MakeSet(node)

union_neighbours = [(0, 1), (1, 0)]
startX, startY = 0, 0
union_current_layer = [(startX, startY)]

while union_current_layer:
    next_layer = []
    for currentX, currentY in union_current_layer:
        for neighbour in union_neighbours:
            nX = currentX + neighbour[0]
            nY = currentY + neighbour[1]
            if 0 <= nX < (m + 2) and 0 <= nY < (n + 2):
                if grid[nY][nX] == grid[currentY][currentX]:
                    Union(nodes[nY][nX], nodes[currentY][currentX])
                
                if nodes[nY][nX].visited == 0:
                    nodes[nY][nX].visited = 1
                    next_layer.append((nX, nY))
    union_current_layer = next_layer


neighbours = [(0, 1), (0, -1), (1, 0), (-1, 0)]
current_layer = [(startX, startY)]
visited = [[0] * (m + 2) for _ in range(n + 2)]
visited[startY][startX] = 1
coast_length = 0

while current_layer:
    next_layer = []
    for currentX, currentY in current_layer:
        if grid[currentY][currentX] == 1:
            for neighbour in neighbours:
                nX = currentX + neighbour[0]
                nY = currentY + neighbour[1]
                if 0 <= nX < (m + 2) and 0 <= nY < (n + 2):
                    if grid[nY][nX] == 0 and Find(nodes[nY][nX]) == Find(nodes[0][0]):
                        coast_length += 1

        for neighbour in union_neighbours:
            nX = currentX + neighbour[0]
            nY = currentY + neighbour[1]
            if 0 <= nX < (m + 2) and 0 <= nY < (n + 2) and visited[nY][nX] == 0:
                visited[nY][nX] = 1
                next_layer.append((nX, nY))
    current_layer = next_layer


stdout.write(str(coast_length))
