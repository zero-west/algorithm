import sys


class SegmentTree:
    def __init__(self, n):
        self.n = 1
        while self.n < n:
            self.n <<= 1
        self.tree = [0] * (self.n * 2)

    def update(self, i, v):
        i += self.n
        self.tree[i] = v
        while i > 1:
            i //= 2
            self.tree[i] = self.tree[i * 2] + self.tree[i * 2 + 1]

    def query(self, left, right):
        answer = 0
        left += self.n
        right += self.n + 1

        while left < right:
            if left & 1:
                answer += self.tree[left]
                left += 1
            if right & 1:
                right -= 1
                answer += self.tree[right]
            left >>= 1
            right >>= 1
        return answer


N = int(sys.stdin.readline())

segment_tree = SegmentTree(N)
result = [None] * N
infos = [None] * N

for idx, val in enumerate(map(int, sys.stdin.readline().split())):
    infos[idx] = (val, idx)
    segment_tree.update(idx, 1)
infos.sort()

complete = 0
for info in infos:
    val, idx = info
    result[idx] = complete + segment_tree.query(0, idx) * val + segment_tree.query(idx + 1, N - 1) * (val - 1)
    complete += val
    segment_tree.update(idx, 0)

for res in result:
    print(res)
