def validate(pillar, bow):
    for cur_x, cur_y in bow:
        if (cur_x, cur_y - 1) in pillar or (cur_x + 1, cur_y - 1) in pillar:
            continue
        if (cur_x - 1, cur_y) in bow and (cur_x + 1, cur_y) in bow:
            continue
        return False

    for cur_x, cur_y in pillar:
        if cur_y == 0 or (cur_x, cur_y - 1) in pillar:
            continue
        if (cur_x - 1, cur_y) in bow or (cur_x, cur_y) in bow:
            continue
        return False

    return True


def solution(n, build_frame):
    pillar = set()  # 기둥
    bow = set()  # 보

    for cur_build in build_frame:
        x, y, a, b = cur_build

        tmp_pillar = set(pillar)
        tmp_bow = set(bow)

        if a == 0:  # 기둥
            if b == 0:
                tmp_pillar.remove((x, y))
            else:
                tmp_pillar.add((x, y))
        else:  # 보
            if b == 0:
                tmp_bow.remove((x, y))
            else:
                tmp_bow.add((x, y))

        if validate(tmp_pillar, tmp_bow):
            pillar = set(tmp_pillar)
            bow = set(tmp_bow)

    answer = [[x, y, 0] for (x, y) in pillar] + [[x, y, 1] for (x, y) in bow]
    answer.sort(key=lambda k: (k[0], k[1]))
    return answer
