#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9;

int T;
int n, m, t;    // 교차로 개수, 도로 개수, 목적지 후보 개수
int s, g, h;    // 예술가들의 출발지, 지나간 도로(g-h)
vector<pair<int, int>> adj[2001];

void dijkstra(int start, vector<int> &dist) {
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto[curDist, cur] = pq.top();
        pq.pop();

        for (const auto &info: adj[cur]) {
            auto[nxt, cost] = info;

            if (dist[nxt] > curDist + cost) {
                dist[nxt] = curDist + cost;
                pq.emplace(dist[nxt], nxt);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        fill(&adj[0], &adj[n] + 1, vector<pair<int, int>>{});

        int flagDist;
        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].emplace_back(b, d);
            adj[b].emplace_back(a, d);
            if ((a == g && b == h) || (a == h && b == g)) flagDist = d;
        }

        set<int> maybe;
        for (int i = 0; i < t; i++) {
            int tmp;
            cin >> tmp;
            maybe.emplace(tmp);
        }
        
        vector<int> dist(n + 1, INF);
        vector<int> dist2(n + 1, INF);

        dijkstra(s, dist);

        adj[0].emplace_back(g, 0);
        adj[0].emplace_back(h, 0);

        dijkstra(0, dist2);

        for (const auto &i: maybe) {
            if (dist2[i] + flagDist + dist2[s] == dist[i]) {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
}
