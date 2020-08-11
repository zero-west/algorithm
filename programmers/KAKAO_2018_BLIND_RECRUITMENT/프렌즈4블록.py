def validate(curR, curC, board, visited):
    dr = [0, 1, 1]
    dc = [1, 0, 1]
    try:
        if board[curR][curC] == board[curR + 1][curC] == board[curR][curC + 1] == board[curR + 1][curC + 1]:
            visited[curR][curC] = True
            for k in range(3):
                visited[curR + dr[k]][curC + dc[k]] = True
            return True
        else:
            return False
    except IndexError:
        return False


def down(r, c, board):
    curR, curC = r, c
    while True:
        try:
            if not board[curR + 1][curC]:
                board[curR + 1][curC] = board[curR][curC]
                board[curR][curC] = 0
                curR += 1
            else:
                break
        except IndexError:
            break


def solution(m, n, board):
    new_board = [list(i) for i in board]
    answer = 0

    while True:
        visited = [[False] * n for _ in range(m)]
        flag = False
        for i in range(m - 1):
            for j in range(n - 1):
                if new_board[i][j]:
                    flag |= validate(i, j, new_board, visited)

        if not flag:
            break

        for i in range(m):
            for j in range(n):
                if visited[i][j]:
                    answer += 1
                    new_board[i][j] = 0
        for j in range(n):
            for i in range(m - 2, -1, -1):
                if new_board[i][j]:
                    down(i, j, new_board)
    return answer
