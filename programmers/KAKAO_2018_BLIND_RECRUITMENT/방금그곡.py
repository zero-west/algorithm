from heapq import *


def convert(converted):
    prev_idx, cur_idx, splitter = -1, -1, []
    for idx, ch in enumerate(converted):
        if ch == '#':
            cur_idx = idx
            splitter.append(converted[prev_idx + 1:cur_idx - 1] + converted[cur_idx - 1].lower())
            prev_idx = idx
    if splitter:
        splitter.append(converted[cur_idx + 1:])
        return ''.join(splitter)
    else:
        return str(converted)


def solution(m, musicinfos):
    new_m = convert(m)

    hubo = []
    for music_idx, music_info in enumerate(musicinfos):
        info = music_info.split(',')
        fir = info[0].split(":")
        sec = info[1].split(":")
        cur_play = (int(sec[0]) * 60 + int(sec[1])) - (int(fir[0]) * 60 + int(fir[1]))

        info[3] = convert(info[3])
        multi = cur_play // len(info[3])
        mod = cur_play % len(info[3])

        cur_str = info[3] * multi + info[3][:mod]
        if new_m in cur_str:
            heappush(hubo, (-cur_play, music_idx, info[2]))
    if hubo:
        return heappop(hubo)[2]
    else:
        return "(None)"