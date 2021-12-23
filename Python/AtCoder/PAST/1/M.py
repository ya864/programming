N, M = map(int, input().split())

# 所持モンスター
mine = []

for i in range(N):
    a, b = map(int, input().split())
    mine.append([a, b])

# お助けモンスター
help = []

for i in range(M):
    c, d = map(int, input().split())
    help.append([c, d])

def check(x):
    mine_calc = []
    for i in range(N):
        mine_calc.append(mine[i][1] - mine[i][0] * x)

    help_calc = []
    for i in range(M):
        help_calc.append(help[i][1] - help[i][0] * x)
    
    mine_calc.sort(reverse=True)
    # お助けモンスターを使う場合
    with_help = sum(mine_calc[:4]) + max(help_calc)
    # お助けモンスターを使わない場合
    without_help = sum(mine_calc[:5])
    
    if with_help >= 0 or without_help >= 0:
        return True
    return False

left = 0
right = 10 ** 6

# Bi - Ai * X  >= 0 となるXの最大値を二分探索で求める
while right - left > 10 ** (-10):
    mid = (left + right) / 2
    if check(mid):
        left = mid
    else:
        right = mid

print(left)
