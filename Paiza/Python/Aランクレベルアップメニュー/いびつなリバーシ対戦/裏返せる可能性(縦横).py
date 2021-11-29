class Point:
    def __init__(self, x, y, s):
        self.x = x
        self.y = y
        self.s = s
        
    # ポイントに情報をセットする
    def set_data(self, inputData):
        self.s = inputData
        
    # ポイントの情報を返す
    def get_data(self):
        return self.s

class Map:
    
    field = []
    # 上下左右に1マスずつ広いマップを作成
    def __init__(self, h, w):
        self.field = [[Point(i+1, j+1, '*') for i in range(h+2)] for j in range(w+2)]
    
    def get_point(self, x, y):
        return self.field[x+1][y+1].get_data()
        
    def set_point(self, x, y, inputData):
        return self.field[x+1][y+1].set_data(inputData)
    
    # TODO:以下の関数は不要なので消すこと
    def set_point_up(self, x, y, inputData):
        if self.get_point(x, y - 1) == '.':
            self.set_point(x, y - 1, inputData)
            self.set_point_up(x, y - 1, inputData)

    def set_point_left(self, x, y, inputData):
        if self.get_point(x - 1, y) == '.':
            self.set_point(x - 1, y, inputData)
            self.set_point_left(x - 1, y, inputData)

    def set_point_down(self, x, y, inputData):
        if self.get_point(x, y + 1) == '.':
            self.set_point(x, y + 1, inputData)
            self.set_point_down(x, y + 1, inputData)

    def set_point_right(self, x, y, inputData):
        if self.get_point(x + 1, y) == '.':
            self.set_point(x + 1, y, inputData)
            self.set_point_right(x + 1, y, inputData)

h, w, y, x = map(int, input().split())

field = Map(h, w)


for i in range(0, h):
    for j in range(0, w):
        field.set_point(j, i, '.')

field.set_point(x, y, '!')
field.set_point_up(x, y, '*')
field.set_point_left(x, y, '*')
field.set_point_down(x, y, '*')
field.set_point_right(x, y, '*')

for i in range(h):
    list = []
    for j in range(w):
        list.append(str(field.get_point(j,i)))
    print(''.join(list))
 
