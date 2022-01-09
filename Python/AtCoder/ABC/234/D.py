import heapq

N, K = map(int, input().split())

P = list(map(int, input().split()))
Q = P[:K]
heapq.heapify(Q)
print(min(Q))
for i in range(K, N):
    min_a = heapq.heappop(Q)
    min_a = max(min_a, P[i])
    heapq.heappush(Q, min_a)
    ans = heapq.heappop(Q)
    print(ans)
    heapq.heappush(Q, ans)