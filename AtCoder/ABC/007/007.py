from collections import deque

R, C = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())

sy -= 1
sx -= 1
gy -= 1
gx -= 1

# マップを用意
M = []

# マップを読み込む
for i in range(R):
    line = input()
    row = []
    for c in line:
        row.append(c)
    M.append(row)

# queueを用意
Q = deque()

# 方向を変化させるための配列
x = [1, 0, -1, 0]
y = [0, 1, 0, -1]

ans = 0
Q.append([sy, sx, 0])

while len(Q) > 0:
    i,j,cnt = Q.popleft()
    if i == gy and j == gx:
        ans == cnt
    for d in range(len(x)):
        if M[i+x[d]][j+y[d]] == ".":
            Q.append([i+x[d], j+y[d], cnt+1])

print(ans)    