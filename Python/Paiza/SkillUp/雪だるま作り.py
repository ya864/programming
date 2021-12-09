
line = input().split()
N = int(line[0])
K = int(line[1])

line = input().split()
nums = list(map(int, line))

nums.sort()
s = 0
e = N-1
cnt = 0

while s < e:
    if((nums[s] + nums[e]) >= K):
        cnt += 1
        s += 1
        e -= 1
    else:
        s += 1

print(cnt)


