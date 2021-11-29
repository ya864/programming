import math
n,m = map(int, input().split())

graph = [[0 for i in range(n)] for j in range(n)]
l = []
for i in range(m):
    a,b = map(int, input().split())
    graph[a-1][b-1] = 1
    l.append([a,b])

for i in range(n):
    print(''.join(map(str, graph[i])))

for i in range(n):
    ans = []
    for j in range(n):
        if graph[i][j] == 1:
            ans.append(j)
    ans = sorted(ans)
    if len(ans) > 0:
        print(''.join(map(str, ans)))
    else:
        print()
