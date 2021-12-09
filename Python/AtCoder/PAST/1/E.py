N, Q = map(int, input().split())

graph = [[-1 for i in range(N)] for j in range(N)]

def _print(graph):
    for i in range(N):
        row = []
        for j in range(N):
            if graph[i][j] == 1:
                row.append("Y")
            else:
                row.append("N")
        print("".join(row))

for i in range(Q):
    query = list(map(int, input().split()))

    if query[0] == 1:
        a = query[1]
        b = query[2]
        a -= 1
        b -= 1
        graph[a][b] = 1

    if query[0] == 2:
        a = query[1]
        a -= 1
        for j in range(N):
            if graph[j][a] == 1:
                graph[a][j] = 1

    if query[0] == 3:
        a = query[1]
        a -= 1

        A = []
        for j in range(N):
            if graph[a][j] == 1:
                A.append(j)

        for j in A:
            for k in range(N):
                if graph[j][k] == 1 and a != k:
                    graph[a][k] = 1

_print(graph)