import math
N = int(input())

def distance(x1, y1, x2, y2):
    return math.sqrt(pow(x2-x1, 2) + pow(y2-y1, 2))

A = list()
for i in range(N):
    A.append(list(map(int, input().split())))
    
ans = 0
for i in range(N-1):
    for j in range(i + 1, N):
       ans = max(ans, distance(A[i][0],A[i][1], A[j][0], A[j][1])) 

print(ans)