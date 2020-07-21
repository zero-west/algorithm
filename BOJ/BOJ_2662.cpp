#include <bits/stdc++.h>

using namespace std;

int N, M;
int info[302][22], dp[302][22];
int invest[302][22];

int solve(int capacity, int idx) {
    if (capacity <= 0 || idx>M) return 0;

    int &ret = dp[capacity][idx];

    if (ret != -1) return ret;

    int Profit;

    Profit = solve(capacity, idx + 1);

    for (int i = 1; i <= N; i++) {
        if (capacity >= i) {
            int tmpProfit = info[i][idx] + solve(capacity - i, idx + 1);
            if (tmpProfit > Profit) {
                Profit = tmpProfit;
                invest[capacity][idx] = i;
            }
        }
    }

    return ret = Profit;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        for (int j = 1; j <= M; j++) {
            cin >> info[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(N, 0) << '\n';

    int tot = N;
    for (int i = 1; i <= M; i++) {
        cout << invest[tot][i] << ' ';
        tot -= invest[tot][i];
    }
    return 0;
}
