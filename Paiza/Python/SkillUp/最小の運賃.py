import math

def dijkstra(A, stations):
    queue = []
    queue.append([0, 0])
    stations[0] = -1
    while len(queue) > 0:
        y,v = map(int, queue.pop(0))
        for i in range(len(stations)):
            if (A[y][i] > 0 and stations[i] > v + A[y][i]) or \
                (A[y][i] > 0 and stations[i] == 0):
                stations[i] = v + A[y][i]
                queue.append([i, (v + A[y][i])])

E,V,T = map(int, input().split())

stations = [0 for i in range(V)]

A = [[0 for i in range(V)] for j in range(V)]

for i in range(E):
    s,e,v = map(int, input().split())
    A[s][e] = v
    A[e][s] = v

dijkstra(A,stations)

print(stations[T])

