import heapq

N, M = map(int, input().split())

# 隣接リスト
graph = [[] for i in range(N)]

#　隣接リストとして読み込む
for i in range(M):
    u, v, c = map(int, input().split())
    # 無向グラフのため、辺の両方向を保存する
    graph[u] = graph.append((v, c))
    graph[v] = graph.append((u, c))


# 頂点がマークされているかどうかを管理する配列
# 頂点iがマークされているとき、marked[i] = True となる
# 最初はどの頂点もマークされていないため、N個のFalseで埋める
marked = [False for i in range(N)]

# マークされている頂点を保持する変数
# 最初はどの頂点もマークされていないため0
# この値がNになったら終了する
marked_count = 0

# 最初に頂点0をマークする
marked[0] = True
marked_count += 1

# 次に選ぶ辺の候補を入れるヒープ
Q = []

# 頂点0に隣接する辺を調べて、ヒープに入れる
for (j, c) in graph[0]:
    # ヒープに選ぶ候補の辺を挿入する
    # (辺の重み、選んだ時にマークする頂点)の形式で保存する
    heapq.heappush(Q, (c, j))

# 最小全域木の重みの合計を保存する変数
sum = 0

# 全ての頂点がマークされるまで繰り返す
while marked_count < N:

    # ヒープから最小の重みの辺を取り出す
    # これは(辺の重み、選んだときにマークする頂点)の形式になっている
    c, i = heapq.heappop(Q)

    # 辺につながる頂点iもすでにマークされていた場合、
    # 操作をスキップする
    if marked[i]:
        continue

    # 頂点iをマークする
    marked[i] = True
    marked_count += 1

    # 使った辺は最小全域木となるため、重みを保存しておく
    sum += c

    # 新たにマークした頂点iに隣接する辺を調べる
    for (j, c) in graph[i]:

        # 辺がつなぐ頂点がすでにマークされていた場合はヒープに入れない
        if marked[j]:
            continue
        heapq.heappush(Q, (c, j))

# 最小全域木の重みの合計
print(sum)