import math

NUM = 7

n = int(input())
a = [0 for i in range(NUM)]
for i in range(n):
    ln = int(input())
    a[ln%NUM] += 1
cnt = 0

for i in range(NUM):
    for j in range(i,NUM):
        for k in range(j,NUM):
            if (i+j+k) % NUM == 0:
                n1,n2,n3 = a[i],a[j],a[k]
                if i == j:
                    n2 -= 1
                if i == k:
                    n3 -= 1
                if j == k:
                    n3 -= 1
                b = (n1 * n2 * n3)
                if i==0 and j==0 and k==0:
                    b /= 6
                elif i==j or j==k or i==k:
                    b /= 2
                cnt += math.floor(b)
print(cnt)
