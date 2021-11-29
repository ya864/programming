H, W, sy, sx, n = map(int, input().split())

# 上下左右に1マスずつ広いマップを作るため、初期位置にプラスする
y = sy+1
x = sx+1

# 上下左右に1マスずつ広いマップを作るため、初期位置にプラスする
map = [['#'] * (W+2) for i in range(H+2)]

# 入力値を代入する。移動可能なマスは.になり上下左右の端に#の壁ができる
for h in range(H):
    line = input()
    for w in range(W):
        map[h+1][w+1] = line[w]

# ある向きで前に進んだ移動に対応するマップを作成
moveX = [0, 1, 0, -1]
moveY = [-1, 0, 1, 0]

# 方角と配列の値をマッピング この問題では使わなくて良いのでコメントアウト
# dir = {'N':0, 'E':1, 'S':2, 'W':3}

d = 0 # 最初は北を向いている

# 北を向いている時に右に進むのは東に向かって進むのと同義なので
# 右ならdirを+1, 左ならdirを-1するする
move = {'R':1, 'L':-1}

for i in range(n):
    d = d + move[input()]
    # 配列の範囲を超えないための処理
    d = 0 if d == 4 else d 
    d = 3 if d < 0 else d
    y += moveY[d]
    x += moveX[d]
    if map[y][x] == '.':
        # ひと回りマップを大きくするためにずらしているので-1する
        print(y-1,x-1)
    else:
        print('Stop')
        break
        