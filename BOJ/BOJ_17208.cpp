#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int dp[101][301][301];
vector<pair<int, int>> info;

int solve(int idx, int c, int p) {
    if (idx >= N) return 0;

    int &ret = dp[idx][c][p];
    if (ret != -1) return ret;

    ret = 0;
    if (c - info[idx].first >= 0 && p - info[idx].second >= 0) {
        ret += max(solve(idx + 1, c - info[idx].first, p - info[idx].second) + 1, solve(idx + 1, c, p));
    } else {
        ret += solve(idx + 1, c, p);
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    info.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> info[i].first >> info[i].second;
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, M, K);
}
