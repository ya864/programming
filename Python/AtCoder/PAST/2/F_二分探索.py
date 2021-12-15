import bisect

N = int(input())

tasks = [[] for i in range(N)]

for i in range(N):
    a, b = map(int, input().split())
    tasks[a - 1].append(b)

ans = 0
# i日目で行えるタスクの一覧
task_day = [0]

for i in range(N):
    for task in tasks[i]:
        index = bisect.bisect(task_day, task)
        task_day.insert(index, task)
        
    ans += task_day[len(task_day) - 1]
    task_day.pop(len(task_day)-1)
    print(ans)