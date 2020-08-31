from heapq import *


def solution(board):
    dr = [-1, 0, 1, 0]
    dc = [0, -1, 0, 1]

    N = len(board)
    min_dist = [[[float('inf')] * 4 for _ in range(N)] for _ in range(N)]

    pq = []
    if not board[0][1]:
        min_dist[0][1][3] = 100
        pq.append((100, (0, 1), 3))
    if not board[1][0]:
        min_dist[1][0][2] = 100
        pq.append((100, (1, 0), 2))

    while pq:
        cur_dist, where, prev = heappop(pq)
        curR, curC = where

        for i in range(4):
            nR, nC, nDist = curR + dr[i], curC + dc[i], cur_dist + 100

            if nR < 0 or nC < 0 or nR >= N or nC >= N or board[nR][nC]:
                continue

            if i % 2 != prev % 2:
                nDist += 500
            elif i != prev:
                continue

            if nDist < min_dist[nR][nC][prev]:
                min_dist[nR][nC][prev] = nDist
                heappush(pq, (nDist, (nR, nC), i))
    return min(min_dist[N - 1][N - 1])
