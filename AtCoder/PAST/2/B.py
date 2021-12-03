Votes = {"a":0, "b":0, "c":0}
S = input()

for c in S:
    Votes[c] += 1

max_v = max(Votes, key=Votes.get)
   
print(max_v)
