def going(stones, curMid, k):
    flager = 0
    for stone in stones:
        if stone - curMid + 1 <= 0:
            flager += 1
        else:
            flager = 0

        if flager >= k:
            return False

    return True

def solution(stones, k):
    left = 1
    right = 200000000
    answer = 1

    if len(stones) == 1:
        return stones[0]
    if k == 1:
        return min(stones)

    while left <= right:
        mid = (left + right) // 2;
        canGo = going(stones, mid, k)

        if canGo:
            left = mid + 1
            answer = max(answer, mid);
        else:
            right = mid - 1

    return answer
