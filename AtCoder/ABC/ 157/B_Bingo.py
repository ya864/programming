class card:
    def __init__(self, num):
        self.value = num
        self.hit = False
    def check(self, num):
        if self.value == num:
            self.hit = True
    
bingo = False

A = []
for i in range(3):
    nums = list(map(int, input().split()))
    row = []
    for num in nums:
        row.append(card(num))
    A.append(row)

N = int(input())

for i in range(N):
    num = int(input())

    for row in A:
        for a in row:
            a.check(num)

for i in range(3):
    if A[i][0].hit and A[i][1].hit and A[i][2].hit:
        bingo = True

for i in range(3):
    if A[0][i].hit and A[1][i].hit and A[2][i].hit:
        bingo = True

if A[0][0].hit and A[1][1].hit and A[2][2].hit:
    bingo = True

if A[0][2].hit and A[1][1].hit and A[2][0].hit:
    bingo = True

if bingo:
    print("Yes")
else:
    print("No")
