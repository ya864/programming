L, R = map(int, input().split())
S = input()

s1 = S[:L - 1]
s2 = S[L - 1:R]
s3 = S[R:]
s2 = s2[::-1]
print(s1 + s2 + s3)