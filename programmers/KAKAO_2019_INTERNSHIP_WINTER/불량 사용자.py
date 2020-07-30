import re, itertools


def solution(user_id, banned_id):
    user_list = str(user_id).translate(str.maketrans("[]", "  ")).replace(" ", "").split(',')
    match_list = [[] for _ in range(len(banned_id))]

    for idx, k in enumerate(banned_id):
        p = re.compile("'" + k.replace('*', '.') + "'")
        for cur_id in user_list:
            if p.findall(cur_id):
                match_list[idx].append(cur_id)

    result = set()
    for val in itertools.product(*match_list):
        if len(set(val)) == len(banned_id):
            result.add(tuple(sorted(val)))

    return len(result)
