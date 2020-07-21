import sys
from collections import deque


def combi(arr, r):
    for i in range(len(arr)):
        if r == 1:
            yield [arr[i]]
        else:
            for nxt in combi(arr[i + 1:], r - 1):
                yield [arr[i]] + nxt


dr = [-1, 0, 1, 0]
dc = [0, -1, 0, 1]

N, M, G, R = map(int, sys.stdin.readline().split())
total = R + G
result = 0
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

hubo = [(row, col) for row, val2 in enumerate(board) for col, val in enumerate(val2) if val == 2]

for case in combi(hubo, R + G):
    for green in combi(case, G):
        boardTmp = [list(k) for k in board]

        tcResult = 0
        visited = [[(-1, 0)] * M for _ in range(N)]
        que = deque(list(case))

        for tu in case:
            boardTmp[tu[0]][tu[1]] = -2  # 일단 뽑은거 전부 빨강 처리
            visited[tu[0]][tu[1]] = (0, -2)  # 다 방문 처리

        for greenIdx in green:
            boardTmp[greenIdx[0]][greenIdx[1]] = -1  # 그린 고른거 처리
            visited[greenIdx[0]][greenIdx[1]] = (0, -1)

        while que:
            curR, curC = que.popleft()
            curColor = -1 if visited[curR][curC][1] == -1 else -2
            curCnt = visited[curR][curC][0]

            if boardTmp[curR][curC] == 3:
                continue

            for i in range(4):
                nR = curR + dr[i]
                nC = curC + dc[i]

                if nR < 0 or nC < 0 or nR >= N or nC >= M or boardTmp[nR][nC] <= 0 or boardTmp[nR][nC] == 3:
                    continue

                if visited[nR][nC][0] != -1:
                    if visited[nR][nC][1] != curColor and visited[nR][nC][0] == curCnt + 1:
                        tcResult += 1
                        boardTmp[nR][nC] = 3
                    continue

                visited[nR][nC] = (curCnt + 1, curColor)
                que.append((nR, nC))
        result = max(tcResult, result)

print(result)
