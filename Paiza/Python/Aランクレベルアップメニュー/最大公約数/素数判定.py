import math
n = int(input())

a = math.floor(math.sqrt(n))+1
factor = 0
for i in range(2, a):
    if(n % i == 0):
        factor +=1

if factor == 0 and n > 1:
    print('YES')
else:
    print('NO')