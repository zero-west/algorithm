def solution(m, n, puddles):
    answer = [[0] * m for _ in range(n)]
    board = [[0] * m for _ in range(n)]
    for puddle in puddles:
        board[puddle[1] - 1][puddle[0] - 1] = 1

    for i in range(m):
        if board[0][i] != 1:
            answer[0][i] = 1
        else:
            break
    for i in range(n):
        if board[i][0] != 1:
            answer[i][0] = 1
        else:
            break

    for i in range(1, m):
        for j in range(1, n):
            if not board[j][i]:
                answer[j][i] = answer[j - 1][i] + answer[j][i - 1]

    return answer[n - 1][m - 1] % 1000000007
