N = int(input())

h = list(map(int, input().split()))

cost = [0 for i in range(N)]

# １つ目のコストはスタート地点からの計算のみ
cost[1] = cost[0] + abs(h[0] - h[1])

# 足場が2個以上ある場合
if N > 2:
    for i in range(2, N):
        cost[i] = min(cost[i - 1] + abs(h[i-1] - h[i]), cost[i - 2] + abs(h[i-2] - h[i]))

print(cost[N-1])

