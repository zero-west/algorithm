def solution(sticker):
    L = len(sticker)
    if L <= 3:
        return max(sticker)
    elif L == 4:
        return max(sticker[0] + sticker[2], sticker[1] + sticker[3])

    dp1 = [0] * L
    dp1[0] = sticker[0]
    dp1[2] = sticker[0] + sticker[2]
    for i in range(3, L - 1):
        dp1[i] = max(dp1[i - 2], dp1[i - 3]) + sticker[i]

    dp2 = [0] * L
    dp2[1] = sticker[1]
    dp2[2] = sticker[2]
    for i in range(3, L):
        dp2[i] = max(dp2[i - 2], dp2[i - 3]) + sticker[i]

    return max(dp1[-3:] + dp2[-3:])
