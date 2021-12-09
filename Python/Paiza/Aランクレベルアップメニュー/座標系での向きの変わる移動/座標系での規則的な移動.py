x,y,n = map(int, input().split())

moveX = [0, 1, 0, -1]
moveY = [-1, 0, 1, 0]

d = 1 # 初期方角は東

size = 300
map = [[0] * size for i in range(size)]
gap = int(size / 2)
map[x + gap][y + gap] = 1

for i in range(n):
    x += moveX[d]
    y += moveY[d]
    map[x + gap][y + gap] = 1
    nextD = 0 if d + 1 == 4 else d + 1
    if map[x + moveX[nextD] + gap][y + moveY[nextD] + gap] == 0:
        d = 0 if d + 1 == 4 else d + 1
print(x,y)