# coding: utf-8
# Your code here!
def hanoi(n, f, t, work):
    if n > 0:
        hanoi(n-1, f, work, t)
        # どこからどこに動かしたかを配列に記録する
        _from.append(f)
        _to.append(t)
        hanoi(n-1, work, t, f)

_from = list()
_to = list()

line = input().split()
n = int(line[0])
t = int(line[1])

# ハノイを解決する
hanoi(n, 0, 2, 1)

sticks = list()
for i in range(3):
    sticks.append(list())

# 一番左の棒にディスクをセットする
for i in range(n):
    sticks[0].append(n-i)

# 棒を記録した配列通りに移動させる
for i in range(t):
    a = _from.pop(0)
    b = _to.pop(0)
    c = sticks[a].pop()
    sticks[b].append(c)

# 棒の状態を出力する
for i in range(3):
    if len(sticks[i]) == 0:
        print("-")
    else:
        ans = map(str, sticks[i])
        ans = ' '.join(ans)
        print(ans)

