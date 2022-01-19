s = list()
for i in range(3):
    s.append(list(input()))

ans = ""
flag = True
t = 0
while flag:
    if len(s[t]) == 0:
        flag = False
    else:
        c = s[t].pop(0)
        t = ord(c) - ord('a')

print(c.upper())