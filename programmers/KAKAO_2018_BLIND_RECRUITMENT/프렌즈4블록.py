def validate(curR, curC, board, visited):
    dr = [0, 1, 1]
    dc = [1, 0, 1]

    if board[curR][curC] == board[curR + 1][curC] == board[curR][curC + 1] == board[curR + 1][curC + 1]:
        visited.add((curR, curC))
        for k in range(3):
            visited.add((curR + dr[k], curC + dc[k]))
        return True
    else:
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
        visited = set()
        flag = False
        for i in range(m - 1):
            for j in range(n - 1):
                if new_board[i][j]:
                    flag |= validate(i, j, new_board, visited)

        if not flag:
            break

        answer += len(visited)
        for r, c in visited:
            new_board[r][c] = 0

        for j in range(n):
            for i in range(m - 2, -1, -1):
                if new_board[i][j]:
                    down(i, j, new_board)
    return answer
