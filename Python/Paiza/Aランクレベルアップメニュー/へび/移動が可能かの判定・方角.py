H, W, sy, sx, d = input().split()

H = int(H)
W = int(W)
sy = int(sy)+1
sx = int(sx)+1

map = [['#'] * (W+2) for i in range(H+2)]

for h in range(H):
    line = input()
    for w in range(W):
        map[h+1][w+1] = line[w]

moveX = [0, 1, 0, -1]
moveY = [-1, 0, 1, 0]
dir = {'N':0, 'E':1, 'S':2, 'W':3}

if map[sy+moveY[dir[d]]][sx+moveX[dir[d]]] == '.':
    print('Yes')
else:
    print('No')