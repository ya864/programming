N = int(input())

tasks = [[] for i in range(N)]

for i in range(N):
    a, b = map(int, input().split())
    tasks[a - 1].append(b)

ans = 0
# i日目で行えるタスクの一覧
cnt = [0 for i in range(101)]

for i in range(N):
    for task in tasks[i]:
        cnt[task] += 1

    for i in range(100, 0, -1):
        if cnt[i] > 0:
            ans += i
            cnt[i] -= 1
            break

    print(ans)