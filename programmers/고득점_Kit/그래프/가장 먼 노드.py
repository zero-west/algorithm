def solution(n, edge):
    from heapq import heappop, heappush

    adj = [[] for _ in range(n + 1)]
    for e in edge:
        a, b = e
        adj[a].append(b)
        adj[b].append(a)

    dist = [float('inf')] * (n + 1)
    dist[1], long_nodes, cur_max = 0, set(), 0
    pq = [(0, 1)]

    while pq:
        cur_dist, cur_node = heappop(pq)
        if cur_max == cur_dist:
            long_nodes.add(cur_node)
        elif cur_max < cur_dist:
            long_nodes = {cur_node}
            cur_max = cur_dist

        for nxt in adj[cur_node]:
            if dist[nxt] >= cur_dist + 1:
                dist[nxt] = cur_dist + 1
                heappush(pq, (dist[nxt], nxt))

    return len(long_nodes)
