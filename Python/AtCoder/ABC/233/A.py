import math
x, y = map(int, input().split())

if x >= y:
    print(0)
else:
    ans = math.ceil((y - x) / 10)
    print(ans)