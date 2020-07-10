import sys
from heapq import *


N, K = map(int, sys.stdin.readline().split())
electricList = list(map(int, sys.stdin.readline().split()))

mapping = {i: -1 for i in range(1, K + 1)}
nxtList = [1000 + i for i in range(K)]

for idx, curE in enumerate(electricList):
    if mapping[curE] == -1:
        mapping[curE] = idx
    else:
        nxtList[mapping[curE]] = idx
        mapping[curE] = idx

res = 0
minHeap = []
maxHeap = []
curPlug = {}

for i, alias in enumerate(electricList):
    if alias in curPlug:
        popInfo = heapreplace(minHeap, (nxtList[i], alias))
        heappush(maxHeap, (-nxtList[i], alias))
        curPlug[alias] = nxtList[i]
        continue

    if len(curPlug) < N:
        heappush(minHeap, (nxtList[i], alias))
        heappush(maxHeap, (-nxtList[i], alias))
        curPlug[alias] = nxtList[i]
    else:
        while True:
            popInfo = heappop(maxHeap)

            if popInfo[1] in curPlug:
                del curPlug[popInfo[1]]
                heappush(minHeap, (nxtList[i], alias))
                heappush(maxHeap, (-nxtList[i], alias))
                curPlug[alias] = nxtList[i]
                break
        heappush(minHeap, (nxtList[i], alias))
        heappush(maxHeap, (-nxtList[i], alias))
        res += 1

print(res)
