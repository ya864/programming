# 辞書に存在するなら値を追加、存在しない場合キーを追加して値を代入
def push(dic, key, val):
    if key in dic:
        dic[key] += val
        return
    dic[key] = val
    
N, X = map(int, input().split())

A = []
for i in range(N):
    A.append(int(input()))
mod = 10 ** 9

states = {}
states[(0, False)] = 1

for i in range(N):
    new_states = {}
    for state, comb in states.items():
        wins, cond = state
        if wins + A[i] <= X:
            # A[i] 全てに勝つ場合
            push(new_states, (wins + A[i], cond), comb)
            
            # A[i] のどこかで負ける場合
            push(new_states, (0, cond), comb * A[i])
        else:
            # X 連勝ちょうどで負ける場合
            push(new_states, (0, True), comb)
            
            # X 連勝未満で負ける場合
            push(new_states, (0, cond), comb * (X - wins))
            
    # 下９桁のみにする
    for key, comb in new_states.items():
        if comb > mod:
            new_states[key] = comb % mod
            
    states = new_states
    
# cond が真か wins が X になっているものの総和を出力
ans = 0
for state, comb in states.items():
    wins, cond = state
    if cond or wins == X:
        ans += comb

print(ans % mod)