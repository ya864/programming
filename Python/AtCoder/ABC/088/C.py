A = []
collect = True

for i in range(3):
    row = list(map(int, input().split()))
    A.append(row)

if A[0][0] - A[0][1] !=  A[1][0] - A[1][1] or A[1][0] - A[1][1] != A[2][0] - A[2][1]:
    collect = False

if A[0][1] - A[0][2] !=  A[1][1] - A[1][2] or A[1][1] - A[1][2] != A[2][1] - A[2][2]:
    collect = False

if A[0][0] - A[1][0] !=  A[0][1] - A[1][1] or A[0][1] - A[1][1] != A[0][2] - A[1][2]:
    collect = False

if A[1][0] - A[2][0] !=  A[1][1] - A[2][1] or A[1][1] - A[2][1] != A[1][2] - A[2][2]:
    collect = False

if collect:
    print("Yes")
else:
    print("No")