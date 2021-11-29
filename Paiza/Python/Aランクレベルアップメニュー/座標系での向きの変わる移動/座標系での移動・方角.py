y,x,n = map(int, input().split())
for i in range(n):
    s = input()
    if s == 'N':
        y -= 1
    if s == 'W':
        x -= 1
    if s == 'E':
        x += 1
    if s == 'S':
        y += 1
    print(y, x)