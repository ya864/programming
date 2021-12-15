N = int(input())

arr = []
for i in range(N):
    a, b = map(int, input().split())
    arr.append([a+b, a, b])

arr.sort(reverse=True)


t1 = 0
t2 = 0
for i in range(N):
    c, a, b = arr[i]
    if i % 2 == 0:
        t1 += a
    else:
        t2 += b

print(t1-t2)
