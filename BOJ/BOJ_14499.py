import sys

dr = [0, 0, -1, 1]
dc = [1, -1, 0, 0]

state = (0, 0, 0, 0, 0, 0)
N, M, x, y, K = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

curR, curC, curState = x, y, state
for curDir in map(int, sys.stdin.readline().split()):
    nR, nC = curR + dr[curDir - 1], curC + dc[curDir - 1]
    nState = curState

    if nR < 0 or nC < 0 or nR >= N or nC >= M:
        continue

    if curDir - 1 == 0:
        nState = (curState[0], curState[5], curState[1], curState[2], curState[4], curState[3])
    elif curDir - 1 == 1:
        nState = (curState[0], curState[2], curState[3], curState[5], curState[4], curState[1])
    elif curDir - 1 == 2:
        nState = (curState[2], curState[1], curState[4], curState[3], curState[5], curState[0])
    elif curDir - 1 == 3:
        nState = (curState[5], curState[1], curState[0], curState[3], curState[2], curState[4])

    if board[nR][nC] == 0:
        board[nR][nC] = nState[5]
    else:
        nState = (nState[0], nState[1], nState[2], nState[3], nState[4], board[nR][nC])
        board[nR][nC] = 0

    curR, curC, curState = nR, nC, nState
    print(nState[2])
