n,m = list(map(int,input().split()))
s = input()
G = s.count('G')
C = s.count('C')
P = s.count('P')

c = list()
p = list()
for i in range(n+1):
    for j in range(n+1):
        if 2*i + 5*j == m and n - i - j >= 0:
            c.insert(len(c), i)
            p.insert(len(p), j)

ans = 0

while len(c) > 0:
    win = 0
    cc = c.pop(0)
    pp = p.pop(0)
    
    win += min(G, pp)
    win += min(P, cc)
    win += min(C, n - cc - pp)
    
    ans = max(ans, win)

print(ans)