import sys

sys.setrecursionlimit(10 ** 9)

N, M = map(int, sys.stdin.readline().split())

items = []

for _ in range(N):
    V, C, K = map(int, sys.stdin.readline().split())

    cnt = 1
    while True:
        if cnt * 2 - 1 > K:
            break
        items.append((V * cnt, C * cnt))
        cnt <<= 1

    remain = K - (cnt - 1)  # 예를 들어 K가 12일 때 1, 2, 4, 12-(1+2+4)=5 개만 있으면 전부 표현 가능.
    items.append((V * remain, C * remain))

it_len = len(items)

# dp[idx][capacity]
dp = [[-1] * 10001 for _ in range(it_len)]


def solve(idx, capacity):
    global dp

    if capacity <= 0 or idx >= it_len:
        return 0

    if dp[idx][capacity] != -1:
        return dp[idx][capacity]

    curWeight = items[idx][0]
    curProfit = items[idx][1]

    if capacity < curWeight:
        dp[idx][capacity] = solve(idx + 1, capacity)
        return dp[idx][capacity]
    else:
        maxProfit = max(solve(idx + 1, capacity), solve(idx + 1, capacity - curWeight) + curProfit)
        dp[idx][capacity] = maxProfit
        return dp[idx][capacity]


print(solve(0, M))
