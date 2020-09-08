from collections import deque


def convert(num, base):
    ret = deque([])
    while num >= base:
        if num % base < 10:
            ret.appendleft(str(num % base))
        else:
            ret.appendleft(chr(65 + num % base - 10))
        num //= base

    if num % base < 10:
        ret.appendleft(str(num))
    else:
        ret.appendleft(chr(65 + num - 10))
    return ''.join(ret)


def solution(n, t, m, p):
    answer, cur_int = '', 0
    total, tot_idx = '', 0
    while len(answer) < t:
        if tot_idx >= len(total):
            total += convert(cur_int, n)
            cur_int += 1
        if tot_idx % m == p - 1:
            answer += total[tot_idx]
        tot_idx += 1
    return answer
