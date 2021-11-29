import math

class Point:
    def __init__(self, k):
        self.k = k

    # ポイントに情報をセットする
    def setData(self, k):
        self.k = k

    # ポイントの情報を返す
    def getData(self):
        return self.k
    
class Graph:
    # n * n のグラフを作成する
    graph = []
    def __init__(self, n):
        self.graph = [[Point(0) for i in range(n)] for j in range(n)]
    
    def getPoint(self, x, y):
        return self.graph[x][y].getData()

    def setPoint(self, x, y, k):
        return self.graph[x][y].setData(k)
        
    
n,m = map(int, input().split())

graph = Graph(n)

for i in range(m):
    a,b,k = map(int, input().split())
    graph.setPoint(a-1,b-1,k) 

for i in range(n):
    ans = []
    for j in range(n):
        ans.append(str(graph.getPoint(i, j)))
    print(''.join(ans))

for i in range(n):
    ans = []
    for j in range(n):
        if graph.getPoint(i,j) > 0:
            ans.append([j, '('+ str(graph.getPoint(i,j)) + ')'])
    ans = sorted(ans, key=lambda x:x[0])
    
    s = []
    for k in range(len(ans)):
        s.append(str(ans[k][0]) + ans[k][1])
    print(''.join(map(str,s)))
    
    
    