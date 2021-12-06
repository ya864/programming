N, M, Q = map(int, input().split())
# N * N の２次元配列を作成する
graph = [[-1 for i in range(N)] for j in range(N)]

# 辺がある場合は、１とする
for i in range(M):
    a, b = map(int, input().split())
    graph[a-1][b-1] = 1
    graph[b-1][a-1] = 1

# 色を受け取って、各頂点に設定する
Colors = list(map(int, input().split()))
for i in range(N):
    # 頂点は縦横の番号が同じところ
    graph[i][i] = Colors[i]

for _ in range(Q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        x = int(query[1])
        x -= 1
        print(graph[x][x])
        for i in range(N):
            if graph[x][i] == 1:
                graph[i][i] = graph[x][x]
    if query[0] == 2:
        x = int(query[1])
        y = int(query[2])
        x -= 1
        print(graph[x][x])
        graph[x][x] = y
