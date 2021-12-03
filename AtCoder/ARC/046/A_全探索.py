import math

N = int(input())
# 今までのゾロ目数の数
z = 0

# 1から555555までの整数を全て調べる。
for i in range(1, 555555 + 1):
    # ゾロ目か調べるために文字列化
    si = str(i)
    # iがゾロ目数かどうか保存する変数
    ok = True
    # siがゾロ目か調べる
    # siの0文字目と違う文字列が含まれていたら、iはゾロ目数ではない
    for s in si:
        if s != si[0]:
            ok = False
    # iがゾロ目数ならzを1増やす
    if ok:
        z += 1
    # iがゾロ目数で、N番目なら答えとして保存
    if ok and z == N:
        ans = i

print(ans)