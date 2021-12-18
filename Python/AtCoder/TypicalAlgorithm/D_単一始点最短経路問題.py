import heapq

N, M = map(int, input().split())

graph = [[] for i in range(N)]

for i in range(M):
    u, v, c = map(int, input().split())
    graph[u].append((v, c))

# 頂点0から各頂点への最短距離を保持する配列
dist = [-1 for i in range(N)]

# ヒープから取り出したことがある頂点かを保持する配列
done = [False for i in range(N)]

# 始点の距離は0
dist[0] = 0

Q = []

# 始点をヒープに追加
heapq.heappush(Q, (0, 0))

while len(Q) > 0:
    d, i = heapq.heappop(Q)

    # もし前にヒープから取り出しているなら、
    # 隣接する頂点を調べるのをスキップする
    if done[i]:
        continue
    
    # すでに取り出した頂点であることを記録する
    done[i] = True

    # 頂点iに隣接する頂点を順番に調べる
    # 見ている頂点をjとする
    # また、iからjへ移動する使う辺の重みをcとする
    for (j, c) in graph[i]:
        
        # jが未訪問だった時、あるいはjへの最短距離が更新可能だった時、
        # jへの最短距離を更新して、ヒープの末尾に追加する
        if dist[j] == -1 or dist[j] > dist[i] + c:
            dist[j] = dist[i] + c
            heapq.heappush(Q, (dist[j], j))

print(dist[N-1])
