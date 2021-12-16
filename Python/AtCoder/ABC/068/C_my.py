N, M = map(int, input().split())

A = [[] for i in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    A[a].append(b)
    A[b].append(a)

flag = False

for i in A[0]:
    for j in A[i]:
        if N-1 in A[j]:
            flag = True

if flag:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
