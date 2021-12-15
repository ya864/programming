N = int(input())

tasks = []

for i in range(N):
    a,b = map(int, input().split())
    # 終了日でソートするため、b(終了日), a(開始日)として格納する
    tasks.append([b,a])

tasks.sort()

ans = 0
last = 0
for i in range(N):
    if tasks[i][1] > last:
        ans += 1
        last = tasks[i][0]

print(ans)