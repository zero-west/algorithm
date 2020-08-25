import sys
from heapq import *

N = int(sys.stdin.readline())
first = int(sys.stdin.readline())
left = [-first]
right = []
print(first)

for idx in range(N - 1):
    cur_int = int(sys.stdin.readline())

    if cur_int <= -left[0]:
        heappush(left, -cur_int)
    else:
        heappush(right, cur_int)

    if len(left) < len(right):
        while len(left) != (idx + 3) // 2:
            heappush(left, -heappop(right))
    else:
        while len(right) < (idx + 2) // 2:
            heappush(right, -heappop(left))

    print(-left[0])
