import sys

sys.setrecursionlimit(10 ** 8)
read = sys.stdin.readline

N, R, Q = map(int, read().split())

adj = [[] for _ in range(N + 1)]
result = [0 for _ in range(N + 1)]

for _ in range(N - 1):
    a, b = map(int, read().split())
    adj[a].append(b)
    adj[b].append(a)


def solve(cur, prev):
    result[cur] = 1
    for nxt in adj[cur]:
        if prev == nxt:
            continue
        result[cur] += solve(nxt, cur)

    return result[cur]


solve(R, 0)

for _ in range(Q):
    q = int(read())
    print(result[q])
