n, m = map(int, input().split())
A = list(map(int, input().split()))


# 0を初期値にしておく
maxLen = 0
# 左端を記録しておくための変数
left = 0
# 右端を記録しておくための変数
right = 0
sumA = 0
while right < n:
    # 総和がmより大きいなら左側を縮めていく
    if(sumA > m):
        sumA -= A[left]
        left += 1
    # 総和がmより小さいなら右側を伸ばしていく
    while sumA <= m and right < n:
        sumA += A[right]
        right += 1
        if(sumA <= m):
            # 今の長さと最大の長さを比べて大きい方を格納する
            maxLen = max(maxLen, right - left)
        
print(maxLen)