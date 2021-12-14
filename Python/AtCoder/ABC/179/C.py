N = int(input())

# 組み合わせの合計
ans = 0

for a in range(1, N):
    # Aを固定した時に、N > A*B　を満たすBの数
    b_count = (N - 1) // a
    ans += b_count

print(ans)
