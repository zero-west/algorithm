#include <bits/stdc++.h>

using namespace std;

int N, K, M;
vector<int> adj[101200];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> M;
    for (int i = 100001; i <= 100000 + M; i++) {
        for (int j = 0; j < K; j++) {
            int n;
            cin >> n;
            adj[i].emplace_back(n);
            adj[n].emplace_back(i);
        }
    }

    vector<int> visited(101200, -1);
    queue<int> que;
    visited[1] = 0;
    que.emplace(1);

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (const auto &nxt: adj[cur]) {
            if (visited[nxt] != -1) continue;
            visited[nxt] = visited[cur] + 1;
            que.emplace(nxt);
        }
    }
    cout << ((visited[N] != -1) ? visited[N] / 2 + 1 : -1);
}
