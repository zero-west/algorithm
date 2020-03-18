from collections import deque
import sys,pprint

dr = [1, 0, -1, 0]
dc = [0, 1, 0, -1]

R, C = map(int, sys.stdin.readline().split())

board = [sys.stdin.readline().rstrip() for _ in range(R)]
visited = [[0] * C for _ in range(R)]

swan = [(R, C) for R, val in enumerate(board) for C, _ in enumerate(val) if board[R][C] == 'L']
board[swan[0][0]] = board[swan[0][0]][:swan[0][1]] + '.' + board[swan[0][0]][swan[0][1]:]
board[swan[1][0]] = board[swan[1][0]][:swan[1][1]] + '.' + board[swan[1][0]][swan[1][1]:]

que = deque([])

for i in range(R):
    for j in range(C):
        for k in range(4):
            nR = i + dr[k]
            nC = j + dc[k]

            if nR < 0 or nC < 0 or nR >= R or nC >= C:
                continue

            if board[i][j] == '.' and board[nR][nC] == 'X':
                que.append((i, j))
                break

while que:
    curR, curC = que.popleft()

    for i in range(4):
        nR = curR + dr[i]
        nC = curC + dc[i]

        if nR < 0 or nC < 0 or nR >= R or nC >= C:
            continue

        if board[nR][nC] == 'X' and visited[nR][nC] == 0:
            visited[nR][nC] = visited[curR][curC] + 1
            que.append((nR, nC))


def flaging(mid):
    global swan, R, C, visited
    flagVisit = [[False] * C for _ in range(R)]
    flagQ = deque([(swan[0][0], swan[0][1])])
    flagVisit[swan[0][0]][swan[0][1]] = True

    while flagQ:
        curR, curC = flagQ.popleft()

        if curR == swan[1][0] and curC == swan[1][1]:
            return True

        for i in range(4):
            nR = curR + dr[i]
            nC = curC + dc[i]

            if nR < 0 or nC < 0 or nR >= R or nC >= C:
                continue

            if flagVisit[nR][nC]:
                continue

            if visited[nR][nC] > mid:
                continue

            flagVisit[nR][nC] = True
            flagQ.append((nR, nC))

    return False


left, right = 0, 1600
result = float('inf')
while left <= right:
    mid = (left + right) // 2

    if (flaging(mid)):
        right = mid - 1
        result = min(result, mid)
    else:
        left = mid + 1

print(result)
