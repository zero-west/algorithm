def solution(lottos, win_nums):
    rank = {6: 1, 5: 2, 4: 3, 3: 4, 2: 5, 1: 6, 0: 6}
    cnt, zero = 0, 0
    for num in lottos:
        if num == 0:
            zero += 1
        elif num in win_nums:
            cnt += 1

    return [rank[cnt+zero], rank[cnt]]
