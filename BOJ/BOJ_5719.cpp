#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int N, M, S, D;
unordered_map<short, int> adj[501];     // 정방향으로 간선 기록
unordered_map<short, int> rev[501];     // 역방향으로 간선 기록

vector<int> dist;       // 최단 거리 기록


int dijkstra() {
    priority_queue<pair<int, short>> pq;
    pq.emplace(0, S);

    dist.assign(N + 1, 1e9);
    dist[S] = 0;

    while (!pq.empty()) {
        auto[curDist, cur] = pq.top();
        curDist *= -1;
        pq.pop();

        if (dist[cur] > curDist) continue;

        for (const auto &info: adj[cur]) {
            auto[nxt, edgeDist] = info;

            if (dist[nxt] > curDist + edgeDist) {
                dist[nxt] = curDist + edgeDist;
                pq.emplace(-dist[nxt], nxt);
            }
        }
    }
    return (dist[D] == 1e9) ? -1 : dist[D];
}


void removeEdge() {
    vector<bool> visited(N, false);
    queue<pair<int, short>> que;

    visited[D] = true;
    que.emplace(0, D);

    while (!que.empty()) {
        auto[curDist, cur] = que.front();
        que.pop();

        for (const auto &info: rev[cur]) {
            auto[nxt, edgeDist] = info;

            if (dist[nxt] + curDist + edgeDist == dist[D]) {
                adj[nxt].erase(cur);
                if (visited[nxt]) continue;
                visited[nxt] = true;
                que.emplace(curDist + edgeDist, nxt);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        fill(&adj[0], &adj[500] + 1, unordered_map<short, int>{});
        fill(&rev[0], &rev[500] + 1, unordered_map<short, int>{});

        cin >> S >> D;

        for (int i = 0; i < M; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u][v] = p;
            rev[v][u] = p;
        }

        dijkstra();
        removeEdge();
        cout << dijkstra() << '\n';
    }
}
