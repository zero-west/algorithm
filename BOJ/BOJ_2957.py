import sys

sys.setrecursionlimit(10 ** 7)

N = int(sys.stdin.readline())
seq = [0] + [int(sys.stdin.readline()) for _ in range(N)]

depth = [0 for _ in range(N + 2)]
parent = [0 for _ in range(N + 2)]
left = [0 for _ in range(N + 2)]
right = [0 for _ in range(N + 2)]


def getParent(a):
    if parent[a] == a:
        return a
    else:
        parent[a] = getParent(parent[a])
        return parent[a]


def unionParent(a, b):
    A, B = parent[a], parent[b]
    parent[A] = B

    left[B] = min(left[B], left[A])
    right[B] = max(right[B], right[A])


for idx in range(N, 0, -1):
    parent[seq[idx]] = seq[idx]

    left[seq[idx]] = seq[idx] - 1
    right[seq[idx]] = seq[idx] + 1

    if getParent(left[seq[idx]]):
        unionParent(left[seq[idx]], seq[idx])

    if getParent(right[seq[idx]]):
        unionParent(right[seq[idx]], seq[idx])


print(0)
ans = 0
for num in seq[2:]:
    depth[num] = max(depth[left[num]], depth[right[num]]) + 1
    ans += depth[num]
    print(ans)
