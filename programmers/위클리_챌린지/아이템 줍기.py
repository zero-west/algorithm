def solution(rectangle, characterX, characterY, itemX, itemY):
    from collections import deque

    answer = 0
    board = [[False] * 108 for _ in range(108)]
    for li in rectangle:
        lc, lr, rc, rr = li
        for r in range(2 * lr, 2 * rr + 1):
            for c in range(2 * lc, 2 * rc + 1):
                board[r][c] = True

    for li in rectangle:
        lc, lr, rc, rr = li
        for r in range(2 * lr + 1, 2 * rr):
            for c in range(2 * lc + 1, 2 * rc):
                board[r][c] = False

    dr = [-1, 0, 1, 0]
    dc = [0, -1, 0, 1]
    que = deque([(characterY * 2, characterX * 2, 0)])
    visited = {(characterY * 2, characterX * 2)}
    while que:
        cur_r, cur_c, cur_cnt = que.popleft()

        if cur_r == 2 * itemY and cur_c == 2 * itemX:
            answer = cur_cnt
            break

        for k in range(4):
            nr, nc = cur_r + dr[k], cur_c + dc[k]
            if not board[nr][nc] or (nr, nc) in visited:
                continue

            visited.add((nr, nc))
            que.append((nr, nc, cur_cnt + 1))

    return answer // 2
