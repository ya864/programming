n,m = map(int, input().split())
arr = [1, 0 , -1]
a = n % 3 - 1
b = m % 3 - 1
cnt = 0

for i in range(a, b+1):
    cnt += arr[i]
print(cnt)