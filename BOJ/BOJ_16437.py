import sys

sys.setrecursionlimit(10 ** 8)

N = int(sys.stdin.readline())
adj = [[] for _ in range(N + 1)]
who = [0 for _ in range(N + 1)]

for idx in range(2, N + 1):
    info = sys.stdin.readline().split()
    adj[int(info[2])].append(idx)

    if info[0] == 'S':
        who[idx] = int(info[1])
    else:
        who[idx] = -int(info[1])

total = 0
who[1] = 0


def dfs(cur):
    ret = who[cur]
    for nxt in adj[cur]:
        ret += dfs(nxt)

    if ret < 0:
        ret = 0
    return ret


print(dfs(1))
