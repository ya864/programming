N = int(input())
S = input()

sum_w = [0]


min_t = 99999999

for i in range(N):
    if S[i] == 'W':
        sum_w.append(int(sum_w[i])+1)
    else:
        sum_w.append(int(sum_w[i]))

for i in range(N):
    # 西側にいる西を向いている人数
    w = sum_w[i]

    # 東側にいる東を向いている人数 i以降の人数　- i以降の西向きの人数
    e = (N - 1 - i) - (sum_w[N] - sum_w[i+1]) 

    min_t = min(min_t, w + e)

print(min_t)