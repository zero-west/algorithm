from collections import OrderedDict, deque
from functools import reduce


def convert(converted):
    hour = '0' + str(converted // 60) if len(str(converted // 60)) == 1 else str(converted // 60)
    minute = '0' + str(converted % 60) if len(str(converted % 60)) == 1 else str(converted % 60)
    return hour + ':' + minute


def solution(n, t, m, timetable):
    timetable = deque(sorted([reduce(lambda x, y: int(x) * 60 + int(y), time.split(':')) for time in timetable]))
    new_table = OrderedDict()
    for time in timetable:
        if time in new_table:
            new_table[time] += 1
        else:
            new_table[time] = 1

    cur_time, que = 540, []

    while cur_time < 540 + (n - 1) * t:
        while timetable and timetable[0] <= cur_time:
            cur_order = timetable[0]
            if len(que) + new_table[cur_order] < m:
                for _ in range(new_table[cur_order]):
                    que.append(timetable.popleft())
                new_table[cur_order] = 0
            else:
                for _ in range(m - len(que)):
                    que.append(timetable.popleft())
                new_table[cur_order] -= m - len(que)
                break
        que = que[m:]
        cur_time += t
    return convert(timetable[m - 1] - 1) if m <= len(timetable) and timetable[m - 1] <= cur_time else convert(cur_time)
