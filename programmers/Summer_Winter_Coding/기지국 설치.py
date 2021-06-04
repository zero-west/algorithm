def solution(n, stations, w):
    from math import ceil
    answer, cover = 0, 2 * w + 1

    answer += ceil((stations[0] - w - 1) / cover) if stations[0] - w - 1 > 0 else 0
    for idx in range(1, len(stations)):
        if stations[idx] - w >= stations[idx - 1] + w:
            answer += ceil((stations[idx] - w - (stations[idx - 1] + w) - 1) / cover)
    answer += ceil((n - (stations[-1] + w)) / cover) if stations[-1] + w < n else 0
    return answer
