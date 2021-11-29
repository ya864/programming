H,W = map(int, input().split())
arr = []

for i in range(H+2):
    arr.append(["#" for i in range(W+2)]) 

for i in range(H):
    str = input()
    for j in range(W):
        arr[i+1][j+1] = str[j]
        
for i in range(1, H+1):
    for j in range(1, W+1):
        if arr[i-1][j] == "#" and arr[i+1][j] == "#":
            print(i-1,j-1)