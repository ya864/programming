import math

class Point:
    def __init__(self, v):
        self.v = v

    # ポイントに情報をセットする
    def setData(self, v):
        self.v = v

    # ポイントの情報を返す
    def getData(self):
        return self.v
    
class Graph:
    # n * n のグラフを作成する
    graph = []
    def __init__(self, n):
        self.graph = [[Point(0) for i in range(n)] for j in range(n)]
    
    def getPoint(self, x, y):
        return self.graph[x][y].getData()

    def setPoint(self, x, y, v):
        return self.graph[x][y].setData(v)
        
    
n,m  = map(int,input().split())

graph = Graph(n)

for i in range(n):
    graph.setPoint(i, i, 1)

for i in range(m):
    a,b = map(int, input().split())
    graph.setPoint(a-1, b-1, 1) 
    graph.setPoint(b-1, a-1, 1)


queue = []
queue.append([1,1])
while len(queue) > 0:
    l = queue.pop(0)
    x,y = map(int, l)
    for i in range(n):
        if graph.getPoint(y,i) == 1:
            graph.setPoint(y,i,0)
            graph.setPoint(i,y,0)
            graph.setPoint(i,i,0)
            graph.setPoint(y,y,0)
            queue.insert(0, [y,i])

isAllVisited = True
for i in range(n):
    for j in range(n):
        if graph.getPoint(i,j) == 1:
            isAllVisited = False

if isAllVisited:
    print('YES')
else:
    print('NO')

    
    