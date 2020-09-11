def solution(n, computers):
    adj = [[] for _ in range(n)]
    for idx in range(n):
        for jdx in range(idx + 1, n):
            if idx != jdx and computers[idx][jdx]:
                adj[idx].append(jdx)
                adj[jdx].append(idx)

    def dfs(cur, t):
        visited[cur] = t
        for nxt in adj[cur]:
            if visited[nxt] <= 0:
                dfs(nxt, t)

    team, visited = 1, [-i for i in range(n)]
    for idx in range(n):
        if visited[idx] <= 0:
            dfs(idx, team)
            team += 1

    return len(set(visited))
