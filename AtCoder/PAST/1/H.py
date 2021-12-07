N = int(input())
C = list(map(int, input().split()))
Q = int(input())

# 販売合計
sell = 0
# セット販売対象の1種類あたりの枚数
s = 0
# 全種類販売の1種類あたりの枚数
z = 0
# セット販売対象の最小値
min_s_c = 100000000000
# 全種類販売の最小値
min_z_c = 100000000000

# 最小値の確認
for i in range(N):
    if i % 2 == 0:
        min_s_c = min(C[i], min_s_c)
    else:
        min_z_c = min(C[i], min_z_c)

for i in range(Q):
    query = list(map(int, input().split()))

    if query[0] == 1:
        x = query[1] - 1
        a = query[2]

        if x % 2 == 0:
            # セット販売対象
            card_x = C[x] - z - s
        else:
            # 全種類販売対象
            card_x = C[x] - z

        if card_x >= a:
            C[x] -= a
            sell += a
            
            # 最小値を更新する
            if x % 2 == 0:
                min_s_c = min(C[x], min_s_c)
            else:
                min_z_c = min(C[x], min_z_c)

    elif query[0] == 2:
        a = query[1]
        # セット対象のCの最小値について、カードがa枚以上あるか調べる
        if min_s_c - s - z >= a:
            s += a
    
    elif query[0] == 3:
        a = query[1]

        # Cの最小値について、カードがa枚以上あるか調べる
        if min(min_s_c - s - z, min_z_c - z) >= a:
            z += a

# セット販売の枚数を合算
for i in range(N):
    if i % 2 == 0:
        sell += s 

# 全種類販売の枚数を合算
sell += z * N

print(sell)
