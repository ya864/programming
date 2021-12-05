N,M,Q = map(int, input().split())
graph = [[-1 for i in range(N)] for j in range(N)]

for i in range(M):
    a,b = map(int, input().split())
    graph[a-1][b-1] = 0
    graph[b-1][a-1] = 0

Colors = list(map(int, input().split()))

for i in range(N):
    graph[i][i] = Colors[i]

for _ in range(Q):
    line = input().split()
    if line[0] == "1":
        x = int(line[1])
        print(graph[x-1][x-1])
        for i in range(N):
            if graph[x-1][i] == 0:
               	graph[i][i] = graph[x-1][x-1]
    if line[0] == "2":
        x = int(line[1])
        y = int(line[2])
        print(graph[x-1][x-1])
        graph[x-1][x-1] = y
