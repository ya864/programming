import math

n = int(input())

flag = True
cnt = 0
ans = ""
a = 0

while flag:
    # n番目のゾロ目数になる数字を探索する
    for i in range(9):
        cnt += 1
        if cnt == n:
            # n番目のゾロ目数に使われている数字を答えとして保存する。
            a = i+1
            flag = False
            
# 答えのゾロ目数に使われている数字で桁数分だけゾロ目数を作る
for i in range(math.ceil(n / 9)):
    ans += str(a)
    
print(ans)
    