import numpy as np

n,m = map(int, input().split())

A = [0 for i in range(n)]
add = [0 for i in range(n+1)]

line = list(map(int, input().split()))
for i in range(n):
    A[i] = line[i]

for i in range(m):
    l,r,a = map(int, input().split())
    add[l-1] += a
    add[r] -= a

for i in range(n):
    print("{:.0f}".format(A[i] + add[i]))
    add[i+1] += add[i]
    