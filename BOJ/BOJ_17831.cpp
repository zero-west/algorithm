#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> tree[200001];
int force[200001];
int parent[200001];
long long dp[200001][2];

long long solve(int cur, int par) {
    long long &ret = dp[cur][par];
    if (ret != -1) return ret;

    ret = (par) ? force[parent[cur]] * force[cur] : 0;

    if (par) {
        for (const auto &nxt: tree[cur]) {
            ret += solve(nxt, 0);
        }
    } else {
        long long no = 0;
        for (const auto &nxt: tree[cur]) {
            no += solve(nxt, 0);
        }

        long long flag = no;
        for (const auto &nxt : tree[cur]) {
            long long temp = no - solve(nxt, 0) + solve(nxt, 1);
            flag = max(flag, temp);
        }
        ret += max(flag, no);
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 2; i <= N; i++) {
        cin >> parent[i];
        tree[parent[i]].emplace_back(i);
    }

    for (int i = 1; i <= N; i++) {
        cin >> force[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0);
}
