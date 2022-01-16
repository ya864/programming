from collections import defaultdict
s = input()
dic = defaultdict()
for c in s:
    if c in dic:
        dic[c] += 1
    else:
        dic[c] = 1

flag = True
for a in dic.values():
    if a % 2 == 1:
        flag = False

if flag:
    print("Yes")
else:
    print("No")