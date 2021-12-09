import copy
n = int(input())
paper = list()
paper_c = list()

def folding(n):
    if n > 0:

        paper_c.clear()
        #copy関数を使わずに配列をコピー。
        #copy関数を使うとdef foldingの外でコピーが保持されない
        for i in range(len(paper)):
            paper_c.append(paper[i])
        paper.clear()
        
        #折り目の最初は必ず０
        paper.append(0)
        for i in range(len(paper_c)):
            #一回前の折り目のコピー
            paper.append(paper_c[i])
            #一回前の折り目に対して交互に0と1を挿入していく
            if i % 2 == 0:
                paper.append(1)
            else:
                paper.append(0)
        folding(n-1)
    
    
folding(n)


ans = list(map(str, paper))
ans = ''.join(ans)

print(ans)
