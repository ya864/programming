import sys
sys.setrecursionlimit(1000000)
N, X = map(int, input().split())
cnt = 0
L = []
for i in range(N):
    lst = list(map(int, input().split()))
    L.append(lst[1:])
    
def dfs(index, arr):
    if index == N:
        a = 1
        for i in range(len(arr)):
            a *= arr[i]
        if a == X:
            global cnt
            cnt += 1
    if index >= N:
        return
    for i in range(len(L[index])):
        arr.append(L[index][i])
        dfs(index + 1, arr)
        arr.pop()
        
    return       

dfs(0, [])
print(cnt)