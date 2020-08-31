def solution(gems):
    gem_set = set(gems)
    total_cnt = len(gem_set)
    if total_cnt == 1:
        return [1, 1]

    answer = []
    p, q = 0, 1
    cur_status = {gems[0]: 1}
    while q < len(gems):
        if gems[q] not in cur_status:
            cur_status[gems[q]] = 1
        else:
            cur_status[gems[q]] += 1
        q += 1

        if len(cur_status) == total_cnt:
            while len(cur_status) == total_cnt:
                cur_status[gems[p]] -= 1
                if cur_status[gems[p]] == 0:
                    del cur_status[gems[p]]
                p += 1
            answer.append((p, q))
    print(answer)
    return list(min(answer, key=lambda k: (k[1] - k[0], k[0])))


print(solution(["XYZ", "XYZ", "XYZ"]))
