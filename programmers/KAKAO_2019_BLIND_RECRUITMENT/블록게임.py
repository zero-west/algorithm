def validate(cur_board, r, c):
    for idx in range(r + 1):
        if cur_board[idx][c] != 0:
            return False
    return True


def solution(board):
    N = len(board)
    mapping = {}
    cur_board = [list(b) for b in board]

    for row in range(N):
        for col in range(N):
            if cur_board[row][col]:
                if cur_board[row][col] in mapping:
                    mapping[cur_board[row][col]].append((row, col))
                else:
                    mapping[cur_board[row][col]] = [(row, col)]

    info = {}
    for cur in mapping:
        cur_min_r, cur_min_c = min([tup[0] for tup in mapping[cur]]), min([tup[1] for tup in mapping[cur]])
        cur_max_r, cur_max_c = max([tup[0] for tup in mapping[cur]]), max([tup[1] for tup in mapping[cur]])
        info[cur] = (cur_min_r, cur_min_c, cur_max_r, cur_max_c)

    lacks = {}
    for cur in info:
        for r in range(info[cur][0], info[cur][2] + 1):
            for c in range(info[cur][1], info[cur][3] + 1):
                if cur_board[r][c] != cur:
                    if cur in lacks:
                        lacks[cur].append((r, c))
                    else:
                        lacks[cur] = [(r, c)]

    result = 0
    while True:
        successes = []
        for lack in lacks:
            flag = True
            for cur_r, cur_c in lacks[lack]:
                if not validate(cur_board, cur_r, cur_c):
                    flag = False

            if flag:
                for r in range(info[lack][0], info[lack][2] + 1):
                    for c in range(info[lack][1], info[lack][3] + 1):
                        cur_board[r][c] = 0
                result += 1
                successes.append(lack)
        if successes:
            for success in successes:
                lacks.pop(success)
                info.pop(success)
                mapping.pop(success)
        else:
            return result
