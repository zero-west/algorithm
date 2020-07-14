import sys
from heapq import *

n = int(sys.stdin.readline())

pq = []
for i in range(2, n+1):
    heappush(pq, -i)
pq.append(-1)
for i in range(n):
    print(-pq[i], end=' ')
