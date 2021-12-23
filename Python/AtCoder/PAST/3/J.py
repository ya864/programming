import bisect 

N, M = map(int, input().split())
A = list(map(int, input().split()))

children = [0 for i in range(N)]
 
for a in A:
    index = bisect.bisect_right(children, -a)
    if index == N:
        print(-1)
    else:
        children[index] = -a
        print(index + 1)
        