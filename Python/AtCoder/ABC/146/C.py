A, B, X = map(int, input().split())

N_Max = 10 ** 9

def binary_search_right(A, B, N, X):
    left = 0
    right = N + 1
    while left + 1 < right:
        mid = (right + left) // 2
        price = A * mid + B * len(str(abs(mid)))
        if price <= X:
            left = mid
        else:
            right = mid
    return left

ans = binary_search_right(A, B, N_Max, X)

if ans == -1:
    print(0)
elif ans > N_Max:
  	print(N_Max)
else:
    print(ans)
