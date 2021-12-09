N, M, Q = map(int, input().split())
# N * 0 の２次元配列を作成する
graph = [[] for j in range(N)]

# 辺がある場合は、１とする
for i in range(M):
    u, v = map(int, input().split())
    # 頂点番号は-1
    u -= 1
    v -= 1
    graph[u].append(v)
    graph[v].append(u)

# 色を受け取って、各頂点に設定する
C = list(map(int, input().split()))

for _ in range(Q):
    query = list(map(int,input().split()))
    if query[0] == 1:
        x = int(query[1])
        x -= 1
        print(C[x])
        # 頂点xに隣接する頂点の色を頂点xと同じ色にする
        for i in graph[x]:
            C[i] = C[x]
    if query[0] == 2:
        x = int(query[1])
        x -= 1
        y = int(query[2])
        print(C[x])
        # 頂点xの色をyに置き換える
        C[x] = y
