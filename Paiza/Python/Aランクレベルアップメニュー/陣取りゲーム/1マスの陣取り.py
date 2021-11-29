class Point:
    def __init__(self, x, y, s, reversed):
        self.x = x
        self.y = y
        self.s = s
        self.reversed = reversed
         
    def set_point(self, input):
        self.s = input
        self.reversed = not self.reversed
        
    def get_point(self):
        return self.x, self.y, self.s, self.reversed
        
h,w = map(int, input().split())

points = [[Point(i+1, j+1, '*', False) for i in range(h+2)] for j in range(w+2)]

for i in range(0, h):
    line = input()
    for j in range(0, w):
        points[i+1][j+1].set_point(line[j])

# ある向きで前に進んだ移動に対応するマップを作成
moveX = [0, 1, 0, -1]
moveY = [-1, 0, 1, 0]

for i in range(h):
    for j in range(w):
        np = points[i+1][j+1].get_point()
        if np[2] == '*' and np[3] == True:
            for k in range(4):
                points[i+1 + moveX[k]][j+1 + moveY[k]].set_point('*')
                
                
for i in range(h):
    list = []
    for j in range(w):
        list.append(points[i+1][j+1].get_point()[2])
    print(''.join(list))