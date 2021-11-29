y,x,D = input().split()
y = int(y)
x = int(x)
d = input()

listY = [-1, 0, 1, 0]
listX = [0, 1, 0, -1]
move = {'N':0, 'E':1, 'S':2, 'W':3}

n = move[D]
n = n + 1 if (d == 'R') else n -1
n = 0 if n == 4 else n

y = y + listY[n]
x = x + listX[n]
