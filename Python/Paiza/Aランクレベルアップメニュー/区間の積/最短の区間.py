n,m = map(int, input().split())
A = list(map(int, input().split()))


# 十分大きな数を初期値にしておく
minLen = 999999999999
# 左端を記録しておくための変数
left = 0
# 右端を記録しておくための変数
right = 0
sumA = 0
while right < n:
    # 総和がmより小さいなら右側に範囲を伸ばしていきながら足していく
    if(sumA < m):
        sumA += A[right]
        right += 1
    # 総和がmより大きくなったなら左側を縮めていく
    if(sumA >= m):
        while sumA >= m:
            sumA -= A[left]
            # 今の長さと最小の長さを比べて小さい方を格納する
            minLen = min(minLen, right - left)
            left += 1
    
if minLen == 999999999999:
    print(-1)
else:
    print(minLen)