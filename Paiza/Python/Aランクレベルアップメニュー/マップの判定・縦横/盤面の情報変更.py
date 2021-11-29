H,W,N = map(int, input().split())
arr = []

for i in range(H):
    str = input()
    arr2 = []
    for j in range(W):
        arr2.append(str[j])
    arr.append(arr2)

for i in range(N):
    x,y = map(int, input().split())
    arr[x][y] = "#"
    
for i in range(H):
    print(''.join(arr[i]))
       