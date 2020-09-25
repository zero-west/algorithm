def solution(money):
    N = len(money)
    if N == 3:
        return max(money[0], money[1], money[2])

    dp = [[0] * 2 for _ in range(N - 1)]
    dp[0][0], dp[1][0], dp[2][0] = money[0], money[1], max(money[0] + money[2], money[1])
    dp[0][1], dp[1][1], dp[2][1] = 0, money[1], max(money[1], money[2])

    for i in range(3, N - 1):
        dp[i][0] = max(dp[i - 2][0] + money[i], dp[i - 3][0] + money[i], dp[i - 1][0])
        dp[i][1] = max(dp[i - 2][1] + money[i], dp[i - 3][1] + money[i], dp[i - 1][1])

    return max(dp[N - 2][0], dp[N - 3][1] + money[N - 1], dp[N - 4][1] + money[N - 1])
