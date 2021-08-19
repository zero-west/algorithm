#include <bits/stdc++.h>

using namespace std;

int N, L, S, E;

bool visited[200010];
queue<pair<int, int>> que;
vector<int> adj[200010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L;

    for (int i = 1; i <= L; i++) {
        int tmp;
        while (true) {
            cin >> tmp;
            if (tmp == -1) break;
            adj[tmp].emplace_back(i + 100000);
            adj[i + 100000].emplace_back(tmp);
        }
    }

    cin >> S >> E;

    visited[S] = true;
    que.emplace(S, 0);

    while (!que.empty()) {
        auto[cur, curDist] = que.front();
        que.pop();

        if (cur == E) {
            cout << ((curDist - 1 > 0) ? curDist - 1 : 0);
            exit(0);
        }

        for (const auto &nxt: adj[cur]) {
            if (visited[nxt]) continue;

            visited[nxt] = true;
            if (nxt > 100000) que.emplace(nxt, curDist + 1);
            else que.emplace(nxt, curDist);
        }
    }

    cout << -1;
}