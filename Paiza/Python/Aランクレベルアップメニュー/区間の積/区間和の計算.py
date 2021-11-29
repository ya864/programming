n = int(input())
A = list(map(int, input().split()))
m = int(input())

# 一度総和を計算しておく
sumA = 0
for i in range(n):
    sumA += A[i]
    A[i] = sumA

# 先頭に0を入れて、uまでの総和 - lまでの総和ができるようにする。
A.insert(0,0)
for i in range(m):
    l,u = map(int, input().split())
    print(A[u+1] - A[l])