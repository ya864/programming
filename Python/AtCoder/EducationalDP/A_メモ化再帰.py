# 再帰上限を増やす
import sys
sys.setrecursionlimit(1000000)

N = int(input())

h = list(map(int, input().split()))

cost = [0 for i in range(N)]

done = [False for i in range(N)]

# メモ化再帰の実装
def rec(i):
    # 計算済みであれば即座に値を返す
    if done[i]:
        return cost[i]
    # そうでなければ値を計算する
    if i == 0:
        cost[i] = 0
    elif i == 1:
        cost[i] = rec(0) + abs(h[0]-h[1])
    else:
        cost[i] = min(rec(i-1) + abs(h[i-1]-h[i]), rec(i-2) + abs(h[i-2]-h[i]))
    # 計算済みフラグを立てて値を返す
    done[i] = True
    return cost[i]

#答えは
print(rec(N-1))

