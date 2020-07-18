import sys
from heapq import *

N, M = map(int, sys.stdin.readline().split())

adj = [[] for _ in range(N + 1)]
parent = [-1] * (N + 1)

for i in range(M):
    a, b, c = map(int, sys.stdin.readline().split())
    adj[a].append((b, c))
    adj[b].append((a, c))

dist = [float('inf')] * (N + 1)
dist[1] = 0
pq = [(0, 1)]

while pq:
    curDist, cur = heappop(pq)

    for nxtInfo in adj[cur]:
        nxt = nxtInfo[0]

        if dist[nxt] < curDist + nxtInfo[1]:
            continue

        dist[nxt] = curDist + nxtInfo[1]
        heappush(pq, (dist[nxt], nxt))
        parent[nxt] = cur

original = dist[N]

maxTime = 0
flag = N
while flag != 1:
    pq = [(0, 1)]
    dist = [float('inf')] * (N + 1)
    dist[1] = 0

    while pq:
        curDist, cur = heappop(pq)

        for nxtInfo in adj[cur]:
            nxt = nxtInfo[0]

            if (cur == flag and nxt == parent[flag]) or (cur == parent[flag] and nxt == flag):
                continue

            if dist[nxt] < curDist + nxtInfo[1]:
                continue

            dist[nxt] = curDist + nxtInfo[1]
            heappush(pq, (dist[nxt], nxt))
    maxTime = max(maxTime, dist[N])
    flag = parent[flag]

print(maxTime - original) if maxTime != float('inf') else print(-1)
