import collections

N, K = map(int, input().split())
A = list(map(int, input().split()))
ans = 0
t = 0

dic = collections.defaultdict(int)

if K != 0:
    dic[0] += 1

for i in A:
    t += i
    dic[t] += 1
    if t - K in dic:
        ans += dic[t - K]

print(ans)
