#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 999999999;

int N, M, Q, dist[1001];
vector<int> adj[1001];
vector<int> res;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> Q;
    fill(dist, dist + 1001, INF);

    pair<int, int> roads[M + 1];
    vector<bool> check(M + 1, false);
    for (int i = 1; i <= M; i++) {
        cin >> roads[i].first >> roads[i].second;
    }

    pair<char, int> queries[Q];
    for (int i = 0; i < Q; i++) {
        cin >> queries[i].first >> queries[i].second;
        if (queries[i].first == 'U') check[queries[i].second] = true;
    }

    for (int i = 1; i <= M; i++) {
        if (!check[i]) adj[roads[i].first].emplace_back(roads[i].second);
    }

    queue<int> que;
    dist[1] = 0;
    que.emplace(1);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (const auto &nxt: adj[cur]) {
            if (dist[nxt] <= dist[cur] + 1) continue;
            dist[nxt] = dist[cur] + 1;
            que.emplace(nxt);
        }
    }

    for (int i = Q - 1; i >= 0; i--) {
        auto[t, p] = queries[i];
        if (t == 'E') {
            res.emplace_back((dist[p] != INF) ? dist[p] : -1);
        } else if (t == 'U') {
            auto[u, v] = roads[p];
            adj[u].emplace_back(v);

            if (dist[v] <= dist[u] + 1) continue;
            dist[v] = dist[u] + 1;
            que.emplace(v);

            while (!que.empty()) {
                int cur = que.front();
                que.pop();

                for (const auto &nxt: adj[cur]) {
                    if (dist[nxt] <= dist[cur] + 1) continue;
                    dist[nxt] = dist[cur] + 1;
                    que.emplace(nxt);
                }
            }
        }
    }

    for (auto it = res.rbegin(); it != res.rend(); it++) {
        cout << *it << '\n';
    }
}
