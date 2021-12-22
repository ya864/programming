N = int(input())
Q = int(input())

row_num = list(range(0, N))
col_num = list(range(0, N))

# 計算式が逆の状態(N*j+i)であればTrue
trans_flag = False

for q in range(Q):
    query = list(map(int, input().split()))
    # クエリタイプ
    t = query[0]
    # クエリ3以外はA,Bが後に続く。0始まりに変換しておく
    if t != 3:
        A = query[1] - 1
        B = query[2] - 1

    if t == 1:
        row_num[A], row_num[B] = row_num[B], row_num[A]
    elif t == 2:
        col_num[A], col_num[B] = col_num[B], col_num[A]
    elif t == 3:
        row_num, col_num = col_num, row_num
        trans_flag = not trans_flag
    else:
        if trans_flag:
            print(N*col_num[B]+row_num[A])
        else:
            print(N*row_num[A]+col_num[B])
