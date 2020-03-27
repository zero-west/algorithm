import heapq
import sys

dr = [-2, -2, -1, -1, 1, 1, 2, 2]
dc = [-1, 1, -2, 2, -2, 2, -1, 1]

m, n = map(int, sys.stdin.readline().split())

board = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]
adjCan = [[[[False] * n for _ in range(m)] for _ in range(n)] for _ in range(m)]
minDist = [[float('inf')] * n for _ in range(m)]
cnt = [[0] * n for _ in range(m)]

SE = [(row, col) for row, val in enumerate(board) for col, val2 in enumerate(val) if val2 == 3 or val2 == 4]
Start = [tu for tu in SE if board[tu[0]][tu[1]] == 3][0]
End = [tu for tu in SE if board[tu[0]][tu[1]] == 4][0]
for tu in SE:
    board[tu[0]][tu[1]] = 1


def init(stR, stC, curR, curC):
    global board, adjCan, m, n

    if adjCan[stR][stC][curR][curC]:
        return

    adjCan[stR][stC][curR][curC] = True

    for i in range(8):
        nR = curR + dr[i]
        nC = curC + dc[i]

        if nR < 0 or nC < 0 or nR >= m or nC >= n:
            continue

        if board[nR][nC] == 2:
            continue

        if board[nR][nC] == 1:
            init(stR, stC, nR, nC)
        adjCan[stR][stC][nR][nC] = True


for i in range(m):
    for j in range(n):
        init(i, j, i, j)

minCushion = float('inf')
result = 0
pq = []
heapq.heappush(pq, (0, Start))
cnt[Start[0]][Start[1]] = 1
minDist[Start[0]][Start[1]] = 0

while pq:
    curDist, loc = heapq.heappop(pq);
    curR, curC = loc

    if adjCan[curR][curC][End[0]][End[1]]:
        if minCushion >= curDist:
            minCushion = curDist
            result += cnt[curR][curC]
        continue

    for i in range(m):
        for j in range(n):
            if not adjCan[curR][curC][i][j]:
                continue

            if board[i][j] != 0:
                continue

            if minDist[curR][curC] + 1 < minDist[i][j]:
                minDist[i][j] = minDist[curR][curC] + 1
                cnt[i][j] = cnt[curR][curC]
                heapq.heappush(pq, (curDist + 1, (i, j)))
            elif minDist[curR][curC] + 1 == minDist[i][j]:
                cnt[i][j] += cnt[curR][curC]

if minCushion != float('inf'):
    print(minCushion)
    print(result)
else:
    print(-1)
