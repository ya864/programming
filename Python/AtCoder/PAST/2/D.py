# 使える文字の一覧
C = "abcdefghijklnmopqrstuvwxyz."

# 文字列Sとマッチする文字列を保持する配列
M = []

# 文字列Tが文字列Sにマッチするかどうかを判定する
def is_match(T, S):
    # Sのi文字目から始まる部分がTとマッチするか調べる
    for i in range(len(S) - len(T) + 1):
        # Sのi文字目から始まる部分がTとマッチしているか保持する
        ok = True
        # Tのj文字目と、Sのi+j文字目を比較する
        for j in range(len(T)):
            # Tのj文字目がSのi+j文字目と異なっていて、
            # かつ、Tのj文字目が"."でもない場合
            # Sのi文字目から始まる部分とはマッチしない
            if S[i + j] != T[j] and T[j] != ".":
                ok = False

        if ok:
            return True
    
    # Sの全ての部分とマッチしなかった場合、Falseを返す
    return False

S = input()

# 1文字の場合
for T in C:
    if is_match(T, S):
        M.append(T)

# 2文字の場合
for c1 in C:
    for c2 in C:
        T = c1 + c2
        if is_match(T,S):
            M.append(T)

# 3文字の場合
for c1 in C:
    for c2 in C:
        for c3 in C:
            T = c1 + c2 + c3
            if is_match(T,S):
                M.append(T)

print(len(M))
