def solution(rows, columns, queries):
    from collections import deque
    board = [[i for i in range(r * columns + 1, (r + 1) * columns + 1)] for r in range(rows)]
    answer = []

    for query in queries:
        l_row, l_col, r_row, r_col = [q - 1 for q in query]
        tmp = deque([i for i in board[l_row][l_col: r_col + 1]]
                    + [i[r_col] for i in board[l_row + 1:r_row + 1]]
                    + [i for i in board[r_row][l_col:r_col]][::-1]
                    + [i[l_col] for i in board[r_row - 1:l_row:-1]])
        answer.append(min(tmp))

        tmp.rotate()
        for idx in range(l_col, r_col + 1):
            board[l_row][idx] = tmp.popleft()
        for idx in range(l_row + 1, r_row + 1):
            board[idx][r_col] = tmp.popleft()
        for idx in range(r_col - 1, l_col - 1, -1):
            board[r_row][idx] = tmp.popleft()
        for idx in range(r_row - 1, l_row, -1):
            board[idx][l_col] = tmp.popleft()

    return answer
