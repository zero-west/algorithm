import sys
from collections import deque

N = int(sys.stdin.readline())
adj = [set() for _ in range(N + 1)]
visited = [set() for _ in range(N + 1)]
time = [-1] * (N + 1)

for idx in range(1, N+1):
    adj[idx] = set(map(int, sys.stdin.readline().split()[:-1]))

M = int(sys.stdin.readline())
que = deque([*map(int, sys.stdin.readline().split())])
for idx in que:
    time[idx] = 0

for cur_time in range(1, N + 3):
    que_len = len(que)

    while que_len:
        que_len -= 1
        cur = que.popleft()
        for nxt in adj[cur]:
            if time[nxt] != -1:
                continue

            if cur not in visited[nxt]:
                visited[nxt].add(cur)

            if len(visited[nxt]) >= (len(adj[nxt]) + 1) // 2:
                time[nxt] = cur_time
                que.append(nxt)
    if not que:
        break

print(' '.join(map(str, time[1:])))
