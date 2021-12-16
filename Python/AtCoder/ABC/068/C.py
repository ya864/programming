from collections import deque

N, M = map(int, input().split())

A = [[] for i in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    A[a].append(b)
    A[b].append(a)

##########################################
# グラフ上で幅優先探索
##########################################

# 頂点0から拡張転への最短距離を保持する配列
# N個の-1で満たしておく(-1の場合は未訪問であることを表す)
dist = []
for _ in range(0, N):
    dist.append(-1)

# 幅優先探索用キュー
Q = deque()

# 視点を追加
Q.append(0)

# 始点となる頂点0への最短距離は0とする
dist[0] = 0

# 幅優先探索で各頂点への最短距離を求める
while len(Q) > 0:
    # キューの先頭の頂点を取り出してiとする
    i = Q.popleft()
    
    # 頂点iに隣接する頂点を順番に見る
    # 見ている頂点をjとする
    for j in A[i]:
        # jが未訪問だったとき、jへの最短距離を更新して、キューの末尾に追加する
        if dist[j] == -1:
            dist[j] = dist[i] + 1
            Q.append(j)

if dist[N - 1] == 2:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
