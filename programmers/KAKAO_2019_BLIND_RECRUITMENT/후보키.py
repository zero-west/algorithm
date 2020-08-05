from itertools import combinations


def solution(relation):
    row_len, col_len = len(relation), len(relation[0])
    available = [i for i in range(col_len)]

    hubo = set()
    for select_cnt in range(1, col_len + 1):
        for select in combinations(available, select_cnt):
            cur_set = set()
            for tup in relation:
                cur_set.add(tuple([tup[i] for i in select]))

            if len(cur_set) == row_len:
                flag = True
                for k in range(1, len(select)):
                    if [inner for inner in combinations(select, k) if inner in hubo]:
                        flag = False
                        break
                if flag:
                    hubo.add(select)
    return len(hubo)
