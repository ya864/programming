N, K = map(int, input().split())
A = list(map(int, input().split()))

def binary_search_left(A, K):
    mid = 0
    left = 0
    right = len(A)
    while left < right:
        mid = (right + left) // 2
        if A[mid] >= K:
            right = mid
        else:
            left = mid + 1 
    return left

if A[len(A)-1] < K:
    print(-1)
else:
    index = binary_search_left(A, K)
    print(index)