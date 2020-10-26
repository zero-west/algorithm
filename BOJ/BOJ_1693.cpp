#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

constexpr long long INF = 1e11;

int N, x, y;
vector<int> adj[100001];
vector<int> tree[100001];
long long dp[100001][19];

void make_tree(int root) {
    queue<int> que;
    vector<bool> visited(N + 1, false);

    visited[root] = true;
    que.emplace(root);

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (const auto &nxt: adj[cur]) {
            if (visited[nxt]) continue;
            visited[nxt] = true;
            que.emplace(nxt);
            tree[cur].emplace_back(nxt);
        }
    }
}

long long solve(int cur, int root_color) {
    long long &ret = dp[cur][root_color];
    if (ret != -1) return ret;
    ret = 0;

    long long plus = INF;
    for (int c = 1; c <= 18; c++) {
        if (c == root_color) continue;

        long long tmp = c;
        for (const auto &nxt: tree[cur]) {
            tmp += solve(nxt, c);
        }
        plus = min(plus, tmp);
    }
    return ret += plus;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    make_tree(1);
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0);
}
