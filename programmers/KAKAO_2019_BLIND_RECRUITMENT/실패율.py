class RUPQ:
    def __init__(self, size):
        self.tree = [0] * (size + 1)
        self.length = size + 1

    def update(self, i, j, val):
        while i < self.length:
            self.tree[i] += val
            i |= i + 1
        j += 1
        while j < self.length:
            self.tree[j] -= val
            j |= j + 1

    def get(self, i):
        res = 0
        while i >= 0:
            res += self.tree[i]
            i = (i & (i + 1)) - 1
        return res


def solution(N, stages):
    fail = {i: 0 for i in range(1, N + 2)}
    fenwick = RUPQ(N + 2)

    for num in stages:
        fail[num] += 1
        fenwick.update(1, num, 1)

    info = []
    for f in fail:
        if f == N + 1:
            continue
        total = fenwick.get(f)
        if total != 0:
            info.append((fail[f] / total, f))
        else:
            info.append((0, f))

    return [i[1] for i in sorted(info, key=lambda k: (-k[0], k[1]))]
