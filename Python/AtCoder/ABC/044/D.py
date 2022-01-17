import math

INF = math.inf
N = int(input())
S = int(input())

def find(b, a):
    if (b < 2):
        return INF
    ret = 0
    while a >= b:
        ret += a % b
        a //= b
    return ret + a

def solve(N, S):
    if N == S:
        return N + 1
    ans = INF
    
    # 全探索1
    for i in range(2, int(math.sqrt(N)) + 1):
        if find(i, N) == S:
            ans = min(ans, i)
    # 全探索2
    for i in range(1, int(math.sqrt(N)) + 1):
        b = (N - S) // i + 1
        if find(b, N) == S:
            ans = min(ans, b)

    if ans == INF:
        return -1
    else:
        return ans

print(solve(N, S))
    