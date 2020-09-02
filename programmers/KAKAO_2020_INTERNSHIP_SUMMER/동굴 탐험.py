from collections import deque
import sys

sys.setrecursionlimit(10 ** 8)


def solution(n, path, order):
    adj = [[] for _ in range(n)]
    tree = [[] for _ in range(n)]
    visited = [False] * n
    for info in path:
        adj[info[0]].append(info[1])
        adj[info[1]].append(info[0])

    # 트리 만들기
    visited[0] = True
    que = deque([0])
    while que:
        cur = que.popleft()
        for nxt in adj[cur]:
            if not visited[nxt]:
                visited[nxt] = True
                que.append(nxt)
                tree[cur].append(nxt)
    for info in order:
        tree[info[0]].append(info[1])

    # 사이클 찾기
    global flag, cnt
    cnt, flag = 0, True
    checked = [-1] * n
    finished = [-1] * n

    def dfs(cur):
        global cnt, flag
        if not flag:
            return

        checked[cur] = cnt
        cnt += 1
        for nxt in tree[cur]:
            # 방문하지 않았다면 방문
            if checked[nxt] == -1:
                dfs(nxt)
            # 제대로 된 방향
            elif checked[cur] < checked[nxt]:
                continue
            # 사이클 발생
            elif finished[nxt] == -1:
                flag = False
                return
        finished[cur] = 1

    dfs(0)
    return flag

