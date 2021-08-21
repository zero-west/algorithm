from typing import List


def solution(cookie: List):
    L = len(cookie)
    answer = 0

    for i, c in enumerate(cookie):
        left_sum, right_sum = c, 0
        left_idx, right_idx = i, i

        while True:
            if left_sum == right_sum:
                answer = max(answer, left_sum)

            if left_sum >= right_sum:
                right_idx += 1
                if right_idx >= L:
                    break

                right_sum += cookie[right_idx]

            elif right_sum > left_sum:
                left_idx -= 1

                if left_idx < 0:
                    break
                left_sum += cookie[left_idx]

    return answer
