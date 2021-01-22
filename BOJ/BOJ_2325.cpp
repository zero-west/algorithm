#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 999999999;

int N, M, parent[1001], dist[1001];
vector<pair<int, int>> adj[1001];

int dijkstra(int removedA, int removedB) {
    fill(dist, dist + 1001, INF);
    dist[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto[curDist, cur] = pq.top();
        curDist *= -1;
        pq.pop();

        if (dist[cur] < curDist) continue;

        for (const auto&[nxt, edgeDist]: adj[cur]) {
            if ((cur == removedA && nxt == removedB) || (cur == removedB && nxt == removedA)) continue;
            if (dist[nxt] <= curDist + edgeDist) continue;
            dist[nxt] = curDist + edgeDist;
            pq.emplace(-(curDist + edgeDist), nxt);
        }
    }
    return dist[N];
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].emplace_back(y, z);
        adj[y].emplace_back(x, z);
    }

    fill(dist, dist + 1001, INF);
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 1);
    dist[1] = 0;

    while (!pq.empty()) {
        auto[curDist, cur] = pq.top();
        curDist *= -1;
        pq.pop();

        if (dist[cur] < curDist) continue;

        for (const auto&[nxt, edgeDist]: adj[cur]) {
            if (dist[nxt] <= curDist + edgeDist) continue;
            dist[nxt] = curDist + edgeDist;
            pq.emplace(-(curDist + edgeDist), nxt);
            parent[nxt] = cur;
        }
    }

    int result = 0;
    for (int cur = N; cur != 0; cur = parent[cur]) {
        result = max(result, dijkstra(cur, parent[cur]));
    }
    cout << result;
}
