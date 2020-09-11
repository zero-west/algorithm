def solution(tickets):
    tickets.sort()
    index = {val: idx for idx, val in enumerate(sorted(set(city for ticket in tickets for city in ticket)))}
    mapping = {index[k]: k for k in index}

    N = len(index)
    adj = [[0] * N for _ in range(N)]
    for ticket in tickets:
        adj[index[ticket[0]]][index[ticket[1]]] += 1

    global tmp, ans, flag
    tmp, ans, flag = [], [], True

    def dfs(cur, depth):
        global tmp, flag, ans
        if not flag:
            return

        tmp.append(mapping[cur])
        if len(tmp) == len(tickets) + 1:
            ans = list(tmp)
            flag = False
            return

        for nIdx in range(N):
            if adj[cur][nIdx]:
                adj[cur][nIdx] -= 1
                dfs(nIdx, depth + 1)
                adj[cur][nIdx] += 1
        tmp.pop()

    dfs(index['ICN'], 1)

    return ans
