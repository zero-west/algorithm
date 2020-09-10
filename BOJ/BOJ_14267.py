import sys

sys.setrecursionlimit(10 ** 8)

n, m = map(int, sys.stdin.readline().split())
adj = [[] for _ in range(n)]
for idx, val in enumerate(map(int, sys.stdin.readline().split())):
    if val != -1:
        adj[val - 1].append(idx)
cost = [0] * n
for _ in range(m):
    i, w = map(int, sys.stdin.readline().split())
    cost[i - 1] += w


def dfs(cur, weight):
    cost[cur] += weight
    for nxt in adj[cur]:
        dfs(nxt, cost[cur])


dfs(0, 0)

for i in cost:
    print(i, end=' ')
