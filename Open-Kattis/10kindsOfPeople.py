import atexit, io, sys


buffer = io.StringIO()
sys.stdout = buffer

@atexit.register 
def write(): 
    sys.__stdout__.write(buffer.getvalue())


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


r, c = map(int, sys.stdin.readline().split())

matrix = []
for _ in range(r):
    matrix.append(sys.stdin.readline().rstrip())

nodes = []
for y in range(r):
    nodes.append([])
    for _ in range(c):
        node = Node()
        nodes[y].append(node)
        MakeSet(node)

startX, startY = 0, 0
curLayer = [(startY, startX)]
neighbors = [(1, 0), (0, 1)]

while curLayer: 
    nextLayer = []
    for currY, currX in curLayer: 
        for toNeighbor in neighbors:
            nx = currX + toNeighbor[1]
            ny = currY + toNeighbor[0]
            if 0 <= nx < c and 0 <= ny < r:
                if matrix[ny][nx] == matrix[currY][currX]:
                    Union(nodes[ny][nx], nodes[currY][currX])
                
                if nodes[ny][nx].visited == 0:
                    nextLayer.append((ny, nx))
                    nodes[ny][nx].visited = 1
    curLayer = nextLayer


n = int(sys.stdin.readline())
for _ in range(n):
    r1, c1, r2, c2 = map(int, sys.stdin.readline().split())
    if(Find(nodes[r1 - 1][c1 - 1]) == Find(nodes[r2 - 1][c2 - 1])):
        print("binary" if matrix[r1 - 1][c1 - 1] == "0" else "decimal")
    else:
        print("neither")
