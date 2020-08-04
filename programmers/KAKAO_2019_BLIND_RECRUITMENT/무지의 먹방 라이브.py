from heapq import *


def solution(food_times, k):
    cur_k = int(k)
    pq = [(val, idx + 1) for idx, val in enumerate(food_times)]
    heapify(pq)

    flag = 0
    while pq:
        cur_val, cur_idx = heappop(pq)

        minus = (cur_val - flag) * (len(pq) + 1)
        if minus == 0:
            continue

        if minus <= cur_k:
            cur_k -= minus
            flag = cur_val
        else:
            heappush(pq, (cur_val, cur_idx))
            cur_k %= len(pq)
            return sorted(pq, key=lambda K: K[1])[cur_k][1]
    return -1
