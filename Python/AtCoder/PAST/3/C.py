A, R, N = map(int, input().split())
 
# 等比数列の公式
# ans = A * (R ** (N -1))
# このまま提出するとTLE

def solve(A, R, N):
    if R == 1:
        return A
    else:
        for i in range(N-1):
            A *= R
            if A > 10 ** 9:
                return "large"
    return A


ans = solve(A, R, N)

print(ans)