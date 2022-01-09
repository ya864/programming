
def func(t):
   return t * t + 2 * t + 3


t = int(input())

ans =  func(func(func(t) + t) + func(func(t)))

print(ans)