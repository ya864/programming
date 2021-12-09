n = int(input())

A = []
for i in range(n):
    line = input()
    row = []
    for c in line:
        row.append(c)
    A.append(row)

for row in range(n - 2, -1, -1):
    for column in range(1, len(A[row]) - 1):
        if A[row][column] == "#":
            if A[row+1][column-1] == "X" or A[row+1][column] == "X" or A[row+1][column+1] == "X":
                A[row][column] = "X"

for row in range(n):
    print("".join(A[row]))