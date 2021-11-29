# coding: utf-8
# Your code here!

line = input().split()
n = int(line[0])
m = int(line[1])

table = [0] * n
ok = True

for i in range(m):
    ok = True
    line = input().split()
    a = int(line[0])
    b = int(line[1])
    
    for j in range(a):
        c = j + b
        if c >= n:
            c -= n
        if table[c] == 1:
            ok = False

    if ok == True:
        for j in range(a):
            c = j + b
            if c >= n:
                c -= n
            table[c] = 1

print(sum(table))