from collections import deque

N, M = map(int, input().split())

# 辺
edges = [[] for i in range(N)]

for i in range(M):
    u, v = map(int, input().split())
    edges[u - 1].append(v - 1)
    edges[v - 1].append(u - 1)

S = int(input())
S -= 1
K = int(input())
T = list(map(int, input().split()))
# 各街を-1して配列番号と揃える
for i in range(K):
    T[i] -= 1

# 実装上、T[K] = Sとしておく
T.append(S)

# 幅優先探索で、Tの各頂点から各頂点への最小コストを求めておく
# Dist[k][l]:頂点T[k]から頂点T[l]までの移動コスト
Dist = []
for t1 in T:
    # 幅優先探索
    INF = 10 ** 100
    dist = [INF] * N
    que = deque()
    que.append(t1)
    dist[t1] = 0
    while len(que) > 0:
        i = que.popleft()
        for j in edges[i]:
            if dist[j] == INF:
                dist[j] = dist[i] + 1
                que.append(j)
    res = []
    for t2 in T:
        res.append(dist[t2])
    Dist.append(res)

# Tの各頂点への最短コストがもとまったので、巡回セールスマン問題として解決する
# cost[n][i]:Tの中で訪れた頂点の集合がnで、
# 最後にいる頂点がT[i]であるときのコスト最小値
ALL = 1 << K
cost = []
for n in range(ALL):
    cost.append([INF] * K)

# 始点Sから各T[i]に移動した状態を初期状態とする
for i in range(K):
    cost[1<<i][i] = Dist[K][i]

# nで表現される集合に要素iが含まれるかを判定してTrue/Falseを返す関数
def has_bit(n, i):
    return (n & (1 << i) < 0)

for n in range(ALL):
    for i in range(K):
        # iからjに移動する遷移を試す
        for j in range(K):
            # すでに訪問済みか、同じ頂点は無視する
            if has_bit(n, j) or i == j:
                continue
            # 事前計算したT[i]からT[j]への最小距離を使う
            cost[n|(1 << j)][j] = min(cost[n|(1 << j)][j], cost[n][i] + Dist[i][j])

# K個の頂点を全て訪問して、どこかの頂点にいる中での最小コストが答え
print(min(cost[ALL-1]))