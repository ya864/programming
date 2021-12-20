N, M = map(int, input().split())

ok = [True for i in range(N+1)]

for i in range(M):
    a = int(input())
    ok[a] = False

MOD = 10 ** 9 + 7

# cnt[i]:i段目まで辿り着く移動方法の数
cnt = [0 for i in range(N+1)]
# 初期条件
cnt[0] = 1

for i in range(1, N+1):
    if ok[i]:
        if i == 1:
            cnt[i] = cnt[i-1]
        else:
            cnt[i] = (cnt[i-1] + cnt[i-2]) % MOD

print(cnt[N])