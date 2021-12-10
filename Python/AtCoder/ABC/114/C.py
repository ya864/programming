N = int(input())

nums = ["3", "5", "7"]

ans = 0
def dfs (s):
    global ans
    use_7 = False
    use_5 = False
    use_3 = False
    if int(s) > N:
        return
    else:
        for i in range(len(s)):
            if s[i] == "3":
                use_3 = True
            if s[i] == "5":
                use_5 = True
            if s[i] == "7":
                use_7 = True
        if use_3 and use_5 and use_7:
            ans += 1
        for i in range(len(nums)):
                dfs(s + nums[i])

dfs("0")

print(ans)
