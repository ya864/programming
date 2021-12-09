import math


def lowerBinarySearch(A, key):
    left = 0
    right = len(A)
    mid = 0
    while left < right:
        mid = math.floor((left + right) / 2)
        if A[mid][0] >= key:
            right = mid
        else:
            left = mid + 1
    return left


def upperBinarySearch(A, key):
    left = 0
    right = len(A)
    mid = 0
    while left < right:
        mid = math.floor((left + right) / 2)
        if A[mid][0] >= key and A[mid][0].startswith(key):
            left = mid + 1
        elif A[mid][0] > key:
            right = mid
        else:
            left = mid + 1
    return right


n, m = map(int, input().split())
A = []
for i in range(n):
    l = list(input().split())
    A.append([l[0], int(l[1])])

A = sorted(A, key=lambda x: x[0])

Aa = [0 for i in range(n + 1)]
if len(A) > 1:
    for i in range(n):
        Aa[i+1] = A[i][1]
        if i > 0:
            Aa[i+1] += Aa[i]
            
for i in range(m):
    ans = 0
    key = input()
    left = lowerBinarySearch(A, key)
    right = upperBinarySearch(A, key)

    ans += Aa[right] - Aa[left]
    print(ans)
