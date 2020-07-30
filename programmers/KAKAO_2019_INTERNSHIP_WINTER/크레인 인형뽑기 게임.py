def solution(board, moves):
    answer = 0
    board_len = len(board)

    stack = []

    for move in moves:
        for row in range(board_len):
            if board[row][move-1]:
                if stack and stack[-1] == board[row][move-1]:
                    stack.pop()
                    answer += 2
                else:
                    stack.append(board[row][move-1])

                board[row][move-1] = 0
                break
        print(stack)

    return answer
