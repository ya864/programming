class Point:
    def __init__(self, x, y, s, reversed):
        self.x = x
        self.y = y
        self.s = s
        self.reversed = reversed
    
    # ポイントに情報をセットする
    def set_point(self, input):
        self.s = input
        self.reversed = not self.reversed
    
    # ポイントの情報を返す
    def get_point(self):
        return self.x, self.y, self.s, self.reversed
        
h,w = map(int, input().split())

# 上下左右に1マスずつ広いマップを作成
field = [[Point(i+1, j+1, '*', False) for i in range(h+2)] for j in range(w+2)]

for i in range(0, h):
    line = input()
    for j in range(0, w):
        field[j+1][i+1].set_point(line[j])

# ある向きで前に進んだ移動に対応するマップを作成
moveX = [0, 1, 0, -1]
moveY = [-1, 0, 1, 0]

queueX = []
queueY = []

for i in range(h):
    for j in range(w):
        np = field[j+1][i+1].get_point()
        if np[2] == '*' and np[3] == True:
            queueX.append(j);
            queueY.append(i);

while len(queueX) > 0 and len(queueY) > 0:
    nx = queueX.pop()
    ny = queueY.pop()    
    for k in range(4):
        nextP = field[nx+1 + moveX[k]][ny+1 + moveY[k]].get_point()
        if nextP[2] == '.':
            field[nx+1 + moveX[k]][ny+1 + moveY[k]].set_point('*')
            queueX.append(nx + moveX[k])
            queueY.append(ny + moveY[k])
                
for i in range(h):
    list = []
    for j in range(w):
        list.append(field[j+1][i+1].get_point()[2])
    print(''.join(list))