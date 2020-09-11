def solution(distance, rocks, n):
    answer = 0
    rocks.sort()
    rocks.append(distance)
    left, right = 1, 1000000000
    while left <= right:
        mid = (left + right) // 2
        cnt, prev = 0, 0
        for idx, cur in enumerate(rocks):
            if mid > cur - prev:
                cnt += 1
            else:
                prev = cur
        if cnt <= n:
            left = mid + 1
            answer = max(answer, mid)
        else:
            right = mid - 1
    return answer
