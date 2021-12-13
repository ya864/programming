N = int(input())

A = []

for i in range(N-1):
    lst = list(map(int, input().split()))
    A.append([0] * (i+1) + lst )

# 集合の全個数 ex.6=111111　で0~63までの64個
ALL = 1<<N

# happy[n]:nで表現される集合をグループにした時の幸福度
happy = [0 for i in range(ALL)]

# nで表現される集合に要素iが含まれているかを判定する
def has_bit(n,i):
    return (n & (1<<i) > 0)

# happyの値を先に計算
for n in range(ALL):
    for i in range(N):
        for j in range(i+1, N):
            if has_bit(n,i) and has_bit(n,j):
                happy[n] += A[i][j]

ans = -999999999999

for n1 in range(ALL):
    for n2 in range(ALL):
        # n1とn2に重複があれば無視する
        if n1 & n2 > 0:
            continue
        # n3 を補集合として求めて答えを更新
        n3 = ALL - 1 - (n1|n2)
        ans = max(ans, happy[n1] + happy[n2] + happy[n3])

print(ans)