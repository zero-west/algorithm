import sys
from collections import deque

sys.setrecursionlimit(10 ** 8)

N = int(sys.stdin.readline())
info = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
result = 0

# DFS 완전탐색
def solve(cur_idx, total):
    global result

    if cur_idx > N:
        return
    else:
        result = max(result, total)
        if cur_idx == N:
            return

    solve(cur_idx + info[cur_idx][0], total + info[cur_idx][1])
    solve(cur_idx + 1, total)


solve(0, 0)
print(result)


# DFS + 메모이제이션
dp = [-1] * (N + 1)


def solve(cur_idx):
    if cur_idx > N:
        return float('-inf')
    elif cur_idx == N:
        return 0

    if dp[cur_idx] != -1:
        return dp[cur_idx]

    dp[cur_idx] = max(solve(cur_idx + 1), solve(cur_idx + info[cur_idx][0]) + info[cur_idx][1])
    return dp[cur_idx]


print(solve(0))


# BFS 완전탐색
que = deque([(0, 0)])
visited = {(0, 0)}

while que:
    total, cur_idx = que.popleft()

    result = max(result, total)

    if cur_idx < N:
        for plus in range(info[cur_idx][0]):
            nxt = cur_idx + plus
            if nxt >= N or nxt + info[nxt][0] > N:
                continue

            nxt_state = nxt + info[nxt][0]
            nxt_total = total + info[nxt][1]

            if (nxt_total, nxt_state) in visited:
                continue

            visited.add((nxt_total, nxt_state))
            que.append((nxt_total, nxt_state))

print(result)


# BFS + 메모이제이션 방법
que = deque([0])
visited = {0: 0}

while que:
    cur_idx = que.popleft()

    result = max(result, visited[cur_idx])

    if cur_idx < N:
        for plus in range(info[cur_idx][0]):
            nxt = cur_idx + plus

            if nxt >= N or nxt + info[nxt][0] > N:
                continue

            nxt_state = nxt + info[nxt][0]
            nxt_total = visited[cur_idx] + info[nxt][1]

            if nxt_state in visited and visited[nxt_state] >= nxt_total:
                continue

            visited[nxt_state] = nxt_total
            que.append(nxt_state)

print(result)


# Bottom-Up DP
dp = [0] * (N + 1)

for idx in range(N - 1, -1, -1):
    nxt = idx + info[idx][0]

    if nxt > N:
        dp[idx] = dp[idx + 1]
    else:
        dp[idx] = max(dp[idx + 1], dp[nxt] + info[idx][1])

print(dp[0])
