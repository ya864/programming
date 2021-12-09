import math
n,m = map(int, input().split())

graph = [[0 for i in range(n)] for j in range(n)]

for i in range(m):
    a,b = map(int, input().split())
    graph[a-1][b-1] = 1
    graph[b-1][a-1] = 1
    
for i in range(n):
    print(''.join(map(str, graph[i])))
    