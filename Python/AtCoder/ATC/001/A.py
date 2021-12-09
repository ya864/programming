# この問題はPypy, Pythonの両方で提出してもMLEになってしまった。
# Cythonで提出したところクリアすることができた。

# 再帰上限を増やす
import sys
sys.setrecursionlimit(10000000)

H, W = map(int, input().split())

M = []

sy = 0
sx = 0
gy = 0
gx = 0

for i in range(H):
    row = []
    S = input()
    for j in range(W):
        row.append(S[j])
        if S[j] == "s":
            sy = i
            sx = j
        if S[j] == "g":
            gy = i
            gx = j
    M.append(row)

# 訪問記録用
visited = [[False for i in range(W)] for j in range(H)]

def dfs(i, j):
    visited[i][j] = True
    for i2, j2 in [[i+1, j], [i, j+1], [i-1, j], [i, j-1]]:
        # マップ範囲内か判定
        if not (0 <= i2 < H and 0 <= j2 < W):
            continue
        else:
            if M[i2][j2] != "#" and not visited[i2][j2]:
                dfs(i2, j2)

dfs(sy, sx)

if visited[gy][gx]:
    print("Yes")
else:
    print("No")
