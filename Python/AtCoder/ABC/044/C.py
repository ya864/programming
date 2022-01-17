N, A = map(int, input().split())
X = list(map(int, input().split()))
dp = [[[0 for i in range(3010)] for j in range(51) ] for k in range(51)]

dp[0][0][0] = 1
for i in range(N):
    for j in range(N):
        for k in range(3000):
            if dp[i][j][k]:
                # カードを選ばない
                dp[i + 1][j][k] += dp[i][j][k]
                # カードを選ぶ
                dp[i + 1][j + 1][k + X[i]] += dp[i][j][k]
    
ans = 0
for i in range(1, N + 1):
    ans += dp[N][i][i * A]

print(ans)