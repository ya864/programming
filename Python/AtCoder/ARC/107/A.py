A, B, C = map(int, input().split())

A_sum = (1 + A) * A // 2
B_sum = (1 + B) * B // 2
C_sum = (1 + C) * C // 2

print(A_sum * B_sum * C_sum % 998244353)