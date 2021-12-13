N, M = map(int, input().split())

S = [0]
C = [0]

for i in range(M):
    s, c  = input().split()
    s_val = 0
    for j in range(N):
        if s[j] == 'Y':
            s_val |= 1<<j
    print(s_val)
    S.append(s_val)
    C.append(int(c))

# 集合としてありえるものの個数
ALL = 1<<N

# cost[i][n]:セットiまで見て揃った部品の集合がnであるときのコスト最小値
cost = []
INF = 10**100
for i in range(M+1):
    cost.append([INF]*ALL)

# 初期条件
cost[0][0] = 0

# iが小さいところから順に計算
for i in range(1, M+1):
    for n in range(ALL):
        # セットiを買わない
        cost[i][n] = min(cost[i][n], cost[i-1][n])
        # セットiを買う
        print(n|S[i])
        cost[i][n|S[i]] = min(cost[i][n|S[i]], cost[i-1][n] + C[i])

# 答えは部品が全部揃っている状態の最小コスト
# ただしINFのままなら、部品を揃えることは不可能
ans = cost[M][ALL-1]
if ans == INF:
    ans = -1

print(ans)

