N = int(input())
# インデックスを0始まりにするため、ダミーの要素を入れる
S = " " + input()
C = [0] + list(map(int, input().split()))
D = [0] + list(map(int, input().split()))

INF = 10 ** 100

# cost[i][j]:i文字目までの扱いを決めて、
# そこまでの累積和がjである時のコスト最小値
cost = [[INF for i in range(N + 1)] for j in range(N + 1)]
cost[0][0] = 0

# 以下の状態を持つ動的計画法
# cost[i][j] = i文字目までの扱いを決め終わって、先頭からその文字までの累積和がjである時に、
# それまで使った操作コストの最小値。ただし、i文字目までの間に条件違反、つまり先頭からの累積和が
# 負になるものがない

for i in range(1, N+1):
    for j in range(i):
        if S[i] == "(":
            # そのまま使う
            cost[i][j + 1] = min(cost[i][j+1], cost[i-1][j])
            # 反転させる
            if j > 0:
                cost[i][j - 1] = min(cost[i][j-1], cost[i-1][j] + C[i])
        else:
            # そのまま使う
            if j > 0:
                cost[i][j - 1] = min(cost[i][j-1], cost[i-1][j])
            # 反転させる
            cost[i][j + 1] = min(cost[i][j+1], cost[i-1][j] + C[i])
        # 削除する
        cost[i][j] = min(cost[i][j], cost[i-1][j] + D[i])

print(cost[N][0])
