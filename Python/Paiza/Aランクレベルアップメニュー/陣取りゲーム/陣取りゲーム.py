class Point:
    def __init__(self, x, y, s, reversed):
        self.x = x
        self.y = y
        self.s = s

    # ポイントに情報をセットする
    def set_point(self, input):
        self.s = input

    # ポイントの情報を返す
    def get_point(self):
        return self.x, self.y, self.s


h, w = map(int, input().split())

first = input()

# 上下左右に1マスずつ広いマップを作成
field = [[Point(i+1, j+1, '*', False) for i in range(h+2)] for j in range(w+2)]

for i in range(0, h):
    line = input()
    for j in range(0, w):
        field[j+1][i+1].set_point(line[j])

moveX = [0, 1, 0, -1]
moveY = [-1, 0, 1, 0]

queueX = []
queueY = []
cntA = 0;
cntB = 0;

sxA, syA, sxB, syB = 0, 0, 0, 0

for i in range(h):
    for j in range(w):
        np = field[j+1][i+1].get_point()
        if np[2] == 'A':
            sxA = j
            syA = i
            cntA += 1
        if np[2] == 'B':
            sxB = j
            syB = i
            cntB += 1
            
if first == 'A':
    queueX.append(sxA)
    queueY.append(syA)
    queueX.append(sxB)
    queueY.append(syB)
else:
    queueX.append(sxB)
    queueY.append(syB)
    queueX.append(sxA)
    queueY.append(syA)        
    
while len(queueX) > 0 and len(queueY) > 0:
    nx = queueX.pop(0)
    ny = queueY.pop(0)
    for k in range(4):
        nextP = field[nx+1 + moveX[k]][ny+1 + moveY[k]].get_point()
        if nextP[2] == '.':
            nowP = field[nx+1][ny+1].get_point()
            field[nx+1 + moveX[k]][ny+1 + moveY[k]].set_point(nowP[2])
            if nowP[2] == 'A':
                cntA += 1
            else:
                cntB += 1
            queueX.append(nx + moveX[k])
            queueY.append(ny + moveY[k])
            
print(cntA, cntB)
if cntA > cntB:
    print('A')
else:
    print('B')

