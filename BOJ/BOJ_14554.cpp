#include <bits/stdc++.h>

using namespace std;

constexpr long long INF = 999999999999999999;
constexpr int MOD = 1e9 + 9;

int N, M, S, E, dp[100001];
long long dist[100001];

vector<pair<int, long long>> adj[100001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> S >> E;
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].emplace_back(y, z);
        adj[y].emplace_back(x, z);
    }

    fill(dist, dist + 100001, INF);
    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, S);
    dist[S] = 0;
    dp[S] = 1;

    while (!pq.empty()) {
        auto[curDist, cur] = pq.top();
        curDist *= -1;
        pq.pop();

        if (dist[cur] < curDist) continue;

        for (const auto&[nxt, edgeDist]: adj[cur]) {
            if (dist[nxt] < curDist + edgeDist) continue;
            if (dist[nxt] == curDist + edgeDist) {
                dp[nxt] += dp[cur];
                dp[nxt] %= MOD;
            } else {
                dist[nxt] = curDist + edgeDist;
                pq.emplace(-(curDist + edgeDist), nxt);
                dp[nxt] = dp[cur] % MOD;
            }
        }
    }
    cout << dp[E];
}
