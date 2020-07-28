import sys

N, M, L = map(int, sys.stdin.readline().split())
where = sorted([0] + list(map(int, sys.stdin.readline().split())) + [L])

left, right = 1, L
result = float('inf')

while left <= right:
    mid = (left + right) // 2

    cnt = 0
    cur_min = float('inf')
    for idx, val in enumerate(where[1:]):
        cur_diff = val - where[idx]

        if cur_diff % mid == 0:
            cnt += cur_diff // mid - 1
        else:
            cnt += cur_diff // mid

    if cnt <= M:
        result = min(result, mid)
        right = mid - 1
    # elif cnt < M:
    #     right = mid - 1
    else:
        left = mid + 1
print(result)
