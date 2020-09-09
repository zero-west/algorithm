import sys
from heapq import *

M, N = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(M)]
start_info = list(map(lambda v: int(v) - 1, sys.stdin.readline().split()))
end_info = list(map(lambda v: int(v) - 1, sys.stdin.readline().split()))

dr = [0, 0, 1, -1]
dc = [1, -1, 0, 0]
turn_right = [2, 3, 1, 0]
turn_left = [3, 2, 0, 1]

min_dist = [[[float('inf')] * 4 for _ in range(N)] for _ in range(M)]
min_dist[start_info[0]][start_info[1]][start_info[2]] = 0
pq = [(0, *start_info)]
while pq:
    cur_dist, curR, curC, cur_dir = heappop(pq)
    nR, nC = curR, curC
    for j in range(3):
        nR += dr[cur_dir]
        nC += dc[cur_dir]

        if nR < 0 or nC < 0 or nR >= M or nC >= N or board[nR][nC]:
            break
        if cur_dist + 1 < min_dist[nR][nC][cur_dir]:
            min_dist[nR][nC][cur_dir] = cur_dist + 1
            heappush(pq, (cur_dist + 1, nR, nC, cur_dir))

    if cur_dist + 1 < min_dist[curR][curC][turn_right[cur_dir]]:
        min_dist[curR][curC][turn_right[cur_dir]] = cur_dist + 1
        heappush(pq, (cur_dist + 1, curR, curC, turn_right[cur_dir]))
    if cur_dist + 1 < min_dist[curR][curC][turn_left[cur_dir]]:
        min_dist[curR][curC][turn_left[cur_dir]] = cur_dist + 1
        heappush(pq, (cur_dist + 1, curR, curC, turn_left[cur_dir]))

print(min_dist[end_info[0]][end_info[1]][end_info[2]])
