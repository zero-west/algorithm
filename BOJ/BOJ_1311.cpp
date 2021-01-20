#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 999999999;

int N, cost[20][20];
int dp[1 << 20][20];

int solve(int state, int curIdx) {
    if (state == (1 << N) - 1) return 0;

    int &ret = dp[state][curIdx];
    if (ret != -1) return ret;

    ret = INF;
    for (int i = 0; i < N; i++) {
        if (state & 1 << i) continue;
        ret = min(ret, cost[curIdx][i] + solve(state | 1 << i, curIdx + 1));
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);
}
