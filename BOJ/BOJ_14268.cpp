#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

vector<int> adj[500001];
int lVec[500001], rVec[500001], num[500001], rev[500001];
int n, m, c;

void dfs(int cur) {
    num[cur] = c;
    lVec[cur] = ++c;
    for (const auto &nxt: adj[cur]) {
        dfs(nxt);
    }
    rVec[cur] = c;
}

long long tree[100001];

void update(int i, int val) {
    for (int k = i; k < n + 1; k |= (k + 1)) {
        tree[k] += val;
    }
}

long getSum(int i) {
    long ret = 0;
    for (int k = i; k >= 0; k = (k & (k + 1)) - 1) {
        ret += tree[k];
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int tmp;
    cin >> tmp;
    for (int i = 2; i <= n; i++) {
        cin >> tmp;
        adj[tmp].emplace_back(i);
    }

    dfs(1);

    for (int i = 0; i < m; i++) {
        int flag, a, b;
        cin >> flag;
        if (flag == 1) {
            cin >> a >> b;
            update(lVec[a] - 1, b);
            update(rVec[a], -b);
        } else {
            cin >> a;
            cout << getSum(num[a]) << '\n';
        }
    }

}