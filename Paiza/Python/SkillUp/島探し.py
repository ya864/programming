n,m = list(map(int, input().split()))
a = [[0 for i in range(n+2)] for j in range(m+2)]
b = [list(map(int, input().split())) for i in range(m)]

for i in range(m):
    for j in range(n):
        a[i+1][j+1] = b[i][j]
           
dirX = [1,-1,0,0]
dirY = [0,0,1,-1]
cnt = 0

def landCnt(h, w):
    nextH = list()
    nextW = list()
    nextH.append(h)
    nextW.append(w)
    nh = 0
    nw = 0
    while len(nextH) > 0 :
        nh = nextH.pop(0)
        nw = nextW.pop(0)
        a[nh][nw] = 9
        for i in range(4):
            if a[nh+dirY[i]][nw+dirX[i]] == 1:
                nextH.insert(0,nh+dirY[i])
                nextW.insert(0,nw+dirX[i])

for i in range(m):
    for j in range(n):
        if a[i+1][j+1] == 1:
            landCnt(i+1,j+1)
            cnt += 1

print(cnt)