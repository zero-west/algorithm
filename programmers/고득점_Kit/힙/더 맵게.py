def solution(scoville, K):
    from heapq import heappop, heapify, heappush

    heapify(scoville)
    answer = 0
    while len(scoville) >= 2 and scoville[0] < K:
        answer += 1

        first = heappop(scoville)
        second = heappop(scoville)

        cur_result = first + second * 2
        heappush(scoville, cur_result)

    return answer if scoville[0] >= K else -1