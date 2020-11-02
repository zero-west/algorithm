#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 999999999;
int T, N, M, K;
vector<tuple<int, int, int>> adj[101];
int dp[101][10001];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        fill(&dp[0][0], &dp[100][10000] + 1, INF);
        fill(&adj[0], &adj[100] + 1, vector<tuple<int, int, int>>{});

        cin >> N >> M >> K;

        while (K--) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            adj[u].emplace_back(v, c, d);
        }

        priority_queue<tuple<int, int, int>> pq;
        pq.emplace(0, 0, 1);
        dp[1][0] = 0;

        bool flag = false;
        while (!pq.empty()) {
            auto[curDist, curCost, cur] = pq.top();
            pq.pop();

            curDist *= -1;
            curCost *= -1;
            if (cur == N) {
                cout << curDist << '\n';
                flag = true;
                break;
            }

            for (const auto &info: adj[cur]) {
                auto[nxt, edgeCost, edgeDist] = info;
                int nCost = edgeCost + curCost;
                int nDist = edgeDist + curDist;

                if (nCost > M) continue;
                if (nDist >= dp[nxt][nCost]) continue;

                dp[nxt][nCost] = nDist;
                pq.emplace(-nDist, -nCost, nxt);
            }
        }
        if (!flag) cout << "Poor KCM" << '\n';
    }
}
