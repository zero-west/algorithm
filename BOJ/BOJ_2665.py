import sys
from heapq import *

n = int(sys.stdin.readline())
board = [list(sys.stdin.readline().rstrip()) for _ in range(n)]
visited = [[float('inf')] * n for _ in range(n)]
visited[0][0] = 0

dr = [-1, 0, 1, 0]
dc = [0, -1, 0, 1]

pq = [(0, 0, 0)]
while pq:
    cost, curR, curC = heappop(pq)

    for i in range(4):
        nR = curR + dr[i]
        nC = curC + dc[i]

        if nR < 0 or nC < 0 or nR >= n or nC >= n:
            continue

        if board[nR][nC] == '0':
            if cost + 1 < visited[nR][nC]:
                visited[nR][nC] = cost + 1
                heappush(pq, (cost+1, nR, nC))
        elif cost < visited[nR][nC]:
            visited[nR][nC] = cost
            heappush(pq, (cost, nR, nC))

print(visited[n - 1][n - 1])
