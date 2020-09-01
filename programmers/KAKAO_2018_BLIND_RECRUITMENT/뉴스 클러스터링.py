from collections import Counter
import math


def solution(str1, str2):
    str1 = str1.lower()
    str2 = str2.lower()

    fir = Counter([str1[idx:idx + 2] for idx in range(len(str1) - 1) if str1[idx:idx + 2].isalpha()])
    sec = Counter([str2[idx:idx + 2] for idx in range(len(str2) - 1) if str2[idx:idx + 2].isalpha()])

    intersect, union, visited = {}, {}, set()

    for f in fir:
        visited.add(f)
        if f in sec:
            intersect[f] = min(fir[f], sec[f])
            union[f] = max(fir[f], sec[f])
        else:
            union[f] = fir[f]
    for s in sec:
        if s in visited:
            continue
        if s in fir:
            intersect[s] = min(fir[s], sec[s])
            union[s] = max(fir[s], sec[s])
        else:
            union[s] = sec[s]
    try:
        return math.trunc(sum(intersect.values()) / sum(union.values()) * 65536)
    except ZeroDivisionError:
        return 65536
