N, M = map(int, input().split())
INF = 99999999999999
graph = [[INF for i in range(N)] for j in range(N)]

# iからiへの同じ頂点同士の距離は0としておく
for i in range(N):
    graph[i][i] = 0

# グラフの辺を受け取り、graphに書き込む
for i in range(M):
    u, v, c = map(int, input().split())
    graph[u][v] = c

# ワーシャルフロイド法
for k in range(N):
    for x in range(N):
        for y in range(N):
            graph[x][y] = min(graph[x][y], graph[x][k] + graph[k][y])

# 答え
ans = 0

# 全ての頂点の組について最短距離を合計する
for i in range(N):
    for j in range(N):
        ans += graph[i][j]

print(ans)
