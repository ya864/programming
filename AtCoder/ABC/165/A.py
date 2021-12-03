K = int(input())
A,B = map(int, input().split())

OK = False

for i in range(A, B+1, 1):
    if i % K == 0:
        OK = True

if OK:
    print("OK")
else:
    print("NG")