from collections import deque

Q = int(input())

cnt_arr = [0 for i in range(27)]

que = deque()

def calc(A):
    all = 0
    for i in range(len(A)):
        all += int(A[i]) ** 2
    return all

for i in range(Q):
    l = input().split()
    if l[0] == "1":
        que.append([l[1], int(l[2])])
        
    elif l[0] == "2":
        cnt = int(l[1])
        while cnt > 0 and len(que) > 0:
            c, x = que[0]
            if x < cnt:
                cnt_arr[ord(c) - ord("a")] += x
                que.popleft()
            else:
                cnt_arr[ord(c) - ord("a")] += cnt
                que[0][1] -= cnt
            cnt -= x
        print(calc(cnt_arr))
        cnt_arr = [0 for i in range(27)]