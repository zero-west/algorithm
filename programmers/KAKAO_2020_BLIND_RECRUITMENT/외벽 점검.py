from collections import deque


def solution(n, weak, dist):
    dist.sort(reverse=True)

    que = deque([weak])
    visited = set()
    visited.add(tuple(weak))

    for idx in range(len(dist)):
        cur_dist = dist[idx]

        que_len = len(que)
        for _ in range(que_len):
            cur_status = que.popleft()
            for point in cur_status:
                start = point
                end = (start + cur_dist) % n

                if start < end:
                    tmp = tuple(i for i in cur_status if i < start or i > end)
                else:
                    tmp = tuple(i for i in cur_status if end < i < start)

                if not tmp:
                    return idx + 1
                elif tmp not in visited:
                    visited.add(tmp)
                    que.append(tmp)
    return -1
