def solution(N, number):
    from functools import reduce
    candidates = [{0}, {N}]
    if number == N:
        return 1

    for cnt in range(2, 9):
        cur = {reduce(lambda x, y: x + y, [N * (10 ** i) for i in range(cnt)])}
        for k in range(1, (cnt + 1) // 2 + 1):
            for a in candidates[k]:
                for b in candidates[cnt - k]:
                    cur.add(a + b)
                    cur.add(a - b)
                    cur.add(b - a)
                    cur.add(a * b)
                    if a != 0:
                        cur.add(b // a)
                    if b != 0:
                        cur.add(a // b)
        if number in cur:
            return cnt
        candidates.append(cur)

    return -1
