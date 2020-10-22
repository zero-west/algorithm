#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int N;
int dist[100001];       // 서브트리 내 최대 거리
int dist2[100001];      // 서브트리 내 두번째 최대 거리
int maxDist[100001];    // 가장 먼 정점과의 거리
int check[100001];

vector<pair<int, short>> adj[100001];
vector<pair<int, short>> tree[100001];

void make_tree(int root) {
    vector<bool> visited(N + 1, false);

    queue<int> que;
    que.emplace(root);
    visited[root] = true;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (const auto &info : adj[cur]) {
            auto[nxt, cost] = info;

            if (visited[nxt]) continue;
            visited[nxt] = true;
            tree[cur].emplace_back(nxt, cost);
            que.emplace(nxt);
        }
    }
}


void sub_dfs(int cur) {
    dist[cur] = dist[cur] = 0;
    for (const auto &info: tree[cur]) {
        auto[nxt, cost] = info;
        
        sub_dfs(nxt);
        
        if (dist[nxt] + cost > dist[cur]) {         // 두 번째에 현재 상태 넣어준 뒤 갱신
            dist2[cur] = dist[cur];
            dist[cur] = dist[nxt] + cost;
        } else if (dist[nxt] + cost > dist2[cur]) { // 두 번째를 갱신 하는경우
            dist2[cur] = dist[nxt] + cost;
        }
    }
}

void solve_dfs(int cur, int parent_far) {
    check[cur] = 2;

    maxDist[cur] = max(dist[cur], parent_far);
    for (const auto &info: tree[cur]) {
        auto[nxt, cost] = info;

        if (dist[cur] == dist[nxt] + cost)  // nxt -> cur -> dist[cur] 이 안 될때
            solve_dfs(nxt, max(parent_far + cost, dist2[cur] + cost));
        else
            solve_dfs(nxt, max(parent_far + cost, dist[cur] + cost));
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    make_tree(1);

    sub_dfs(1);
    solve_dfs(1, 0);

    sort(&maxDist[1], &maxDist[N] + 1);
    cout << maxDist[N - 2];
}
