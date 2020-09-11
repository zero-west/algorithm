def solution(n, times):
    answer, left, right = float('inf'), 1, 100000000000000

    while left <= right:
        mid = (left + right) // 2

        cur_can = 0
        for time in times:
            cur_can += mid // time

        if cur_can >= n:
            answer = min(answer, mid)
            right = mid - 1
        else:
            left = mid + 1

    return answer
