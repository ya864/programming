import math
n,m = map(int, input().split())

ans = 0
flag = True
while flag:
    a = m % n
    if(a == 0):
        flag = False
        ans = n
    m = n
    n = a

print(ans)