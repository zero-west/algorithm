import sys

sys.setrecursionlimit(10 ** 8)

answer = 0


def solution(a, edges):
    visited = [False] * 300001

    adj = [[] for _ in range(len(a) + 5)]
    for edge in edges:
        adj[edge[0]].append(edge[1])
        adj[edge[1]].append(edge[0])

    def dfs(cur):
        global answer

        visited[cur] = True
        for nxt in adj[cur]:
            if visited[nxt]:
                continue
            dfs(nxt)
            answer += abs(a[nxt])
            a[cur] += a[nxt]

    dfs(0)

    return -1 if a[0] != 0 else answer
