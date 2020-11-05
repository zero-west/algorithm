#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

constexpr long long INF = 99999999999999;
int N, M, K;

priority_queue<tuple<long long, short, int>> pq;
vector<pair<int, int>> adj[10001];
long long maxDist[10001][21];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].emplace_back(v, d);
        adj[v].emplace_back(u, d);
    }

    fill(&maxDist[0][0], &maxDist[10000][20] + 1, INF);

    pq.emplace(0L, 0, 1);
    maxDist[1][0] = 0;

    while (!pq.empty()) {
        auto[curDist, curPack, cur] = pq.top();
        curDist *= -1;
        pq.pop();

        if (maxDist[cur][curPack] < curDist) continue;

        for (const auto &info: adj[cur]) {
            auto[nxt, edgeDist] = info;

            if (curPack < K && curDist < maxDist[nxt][curPack + 1]) {
                maxDist[nxt][curPack + 1] = curDist;
                pq.emplace(-curDist, curPack + 1, nxt);
            }

            if (curDist + edgeDist < maxDist[nxt][curPack]) {
                maxDist[nxt][curPack] = curDist + edgeDist;
                pq.emplace(-maxDist[nxt][curPack], curPack, nxt);
            }
        }
    }

    cout << *min_element(&maxDist[N][0], &maxDist[N][K] + 1);
}
