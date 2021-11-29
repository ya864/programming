n,m = map(int, input().split())

minN = 99999999999

A = [0 for i in range(n)]

line = list(map(int, input().split()))
for i in range(n):
    A[i] = line[i]

mul = 1
index = 0
for i in range(n):
    mul = mul * A[i]
    if mul == 0:
        mul = 1
        index = i+1
    while m <= mul and index <= i:
        mul = mul / A[index]
        minN = min(minN, (i+1 - index))
        index += 1
        
print(minN)
        
        