N = int(input())

A = []
for i in range(N):
    a = list(map(int, input().split()))
    A.append(a)

# 経路全ての組み合わせの最大数
ALL = 1<<N

cost = []
# cost[n][i]:訪れた都市の集合がn, 最後に訪れた都市がiである時のコスト
for n in range(ALL):
    cost.append([10**100 for i in range(N)])

# 初期条件。最初にいる時の始点はnに含めない
cost[0][0] = 0

# nで表現される集合に要素iが含まれるかを判定してTrue/Falseを返す関数
def has_bit(n, i):
    return (n & (1<<i) > 0)

for n in range(ALL):
    for i in range(N):
        # iからjに移動する遷移を試す
        for j in range(N):
            # すでに訪問済みか、同じ都市は無視する
            if has_bit(n, j) or i == j:
                continue
            cost[n|(1<<j)][j] = min(cost[n|(1<<j)][j], cost[n][i] + A[i][j])

# 全都市を訪問して始点に戻ってくる最小コストが答え
print(cost[ALL-1][0])