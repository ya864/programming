H, W = map(int, input().split())

A = []
for i in range(H):
    A.append(input())

cnt = [[0 for i in range(W)] for i in range(H)]
cnt[0][0] = 1

MOD = 10 ** 9 + 7

for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            continue
        if i > 0:
            cnt[i][j] += cnt[i - 1][j]
        if j > 0:
            cnt[i][j] += cnt[i][j - 1]

    cnt[i][j] %= MOD

print(cnt[H-1][W-1])
