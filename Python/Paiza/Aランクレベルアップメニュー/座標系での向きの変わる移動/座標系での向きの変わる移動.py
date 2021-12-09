x,y,n = map(int, input().split())

moveX = [0, 1, 0, -1]
moveY = [-1, 0, 1, 0]

dirList = {'L': -1, 'R': 1}
d = 0 # 初期方角は北

size = 300
map = [[0] * size for i in range(size)]
gap = int(size / 2)

for i in range(n):
    d = d + dirList[input()]
    d = 0 if d == 4 else d 
    d = 3 if d < 0 else d
    x += moveX[d]
    y += moveY[d]
    print(x, y)
    