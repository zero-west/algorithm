from collections import deque

# 가로상태: 우, 하, 상, 좌, 아래쪽을 확인, 위쪽 확인, 아래쪽 확인, 위쪽을 확인
# 세로상태: 우, 하, 상, 좌, 왼쪽을 확인, 오른쪽 확인, 왼쪽 확인, 오른쪽을 확인
dr = [[(0, 0), (1, 1), (-1, -1), (0, 0), (1, 0), (-1, 0), (0, 1), (0, -1)],
      [(0, 0), (1, 1), (-1, -1), (0, 0), (1, 0), (1, 0), (0, -1), (0, -1)]]

dc = [[(1, 1), (0, 0), (0, 0), (-1, -1), (1, 0), (1, 0), (0, -1), (0, -1)],
      [(1, 1), (0, 0), (0, 0), (-1, -1), (-1, 0), (1, 0), (0, -1), (0, 1)]]

def solution(board):
    visited = {}
    answer = float('inf')
    N = len(board)

    visited[(0, 0, 0, 1)] = True
    visited[(0, 1, 0, 0)] = True
    que = deque([(0, 0, 0, 1, 0, 0)])

    while que:
        a, b, c, d, curDir, time = que.popleft()

        if (a, b) > (c, d):
            a, c = c, a
            b, d = d, b

        if c == N - 1 and d == N - 1:
            answer = min(answer, time)

        for i in range(8):
            na, nb = a + dr[curDir][i][0], b + dc[curDir][i][0]
            nc, nd = c + dr[curDir][i][1], d + dc[curDir][i][1]
            nDir = (curDir ^ 1) if i >= 4 else curDir

            if na < 0 or nc < 0 or na >= N or nc >= N or nb < 0 or nd < 0 or nb >= N or nd >= N:
                continue

            if i >= 4:
                if curDir == 0:
                    if i % 2 == 0:
                        if a + 1 < N and c + 1 < N:
                            if board[a + 1][b] == 1 or board[c + 1][d] == 1:
                                continue
                    else:
                        if a - 1 >= 0 and c - 1 >= 0:
                            if board[a - 1][b] == 1 or board[c - 1][d] == 1:
                                continue
                else:
                    if i % 2 == 0:
                        if b - 1 >= 0 and d - 1 >= 0:
                            if board[a][b - 1] == 1 or board[c][d - 1] == 1:
                                continue
                    else:
                        if b + 1 < N and d + 1 < N:
                            if board[a][b + 1] == 1 or board[c][d + 1] == 1:
                                continue

            if board[na][nb] == 1 or board[nc][nd] == 1:
                continue

            if (na, nb, nc, nd) in visited or (nc, nd, na, nb) in visited:
                continue

            visited[(na, nb, nc, nd)] = True
            visited[(nc, nd, na, nb)] = True
            que.append((na, nb, nc, nd, nDir, time + 1))

    return answer

print(solution([[0, 0, 0, 1, 1], [0, 0, 0, 1, 0], [0, 1, 0, 1, 1], [1, 1, 0, 0, 1], [0, 0, 0, 0, 0]]))
