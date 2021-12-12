N, L = map(int, input().split())
hurdles = list(map(int, input().split()))
# ハードルのある座標の登録
H = [False for i in range(L+1)]
for hurdle in hurdles:
    H[hurdle] = True

cost = [9999999999 for i in range(L+1)]

cost[0] = 0

T1, T2, T3 = map(int,input().split())

for i in range(1, L+1):
    # 行動1
    cost[i] = min(cost[i], cost[i-1] + T1)
    # 行動2
    if i >= 2:
        cost[i] = min(cost[i], cost[i-2] + T1 + T2)
    # 行動3
    if i >= 4:
        cost[i] = min(cost[i], cost[i-4] + T1 + (3 * T2))
    if H[i]:
        cost[i] += T3
    
# 答えは座標Lに丁度止まるか、L-3〜L-1の座標からジャンプ中に到達したもの
ans = cost[L]
for i in [L-3, L-2, L-1]:
    if i >= 0:
        ans = min(ans, cost[i] + T1//2 + T2//2 + T2*(L-i-1))

print(ans)
