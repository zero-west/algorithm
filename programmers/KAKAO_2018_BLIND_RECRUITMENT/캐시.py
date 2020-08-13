def solution(cacheSize, cities):
    if cacheSize == 0:
        return 5 * len(cities)
    answer = 0
    cur_time = 0
    cur_set = {}

    for city in cities:
        cur_time += 1

        if city.lower() in cur_set:
            cur_set[city.lower()] = cur_time
            answer += 1
        else:
            answer += 5
            if len(cur_set) == cacheSize:
                del_key = min(cur_set.keys(), key=lambda k: cur_set[k])
                del cur_set[del_key]
                cur_set[city.lower()] = cur_time
            else:
                cur_set[city.lower()] = cur_time
    return answer
