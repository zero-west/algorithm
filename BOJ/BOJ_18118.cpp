#include <bits/stdc++.h>

using namespace std;

int T;
int n, m;
long long dp[11][100001];


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--) {
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;

        for (int i = 0; i <= 11; i++) {
            if (i == 10) continue;
            dp[1][i % m] = i;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= 11; j++) {
                if (j == 10) continue;

                for (int k = 0; k < m; k++) {
                    long long val = (j != 11) ? dp[i - 1][k] * 10 + j : dp[i - 1][k] * 100 + j;
                    dp[i][val % m] = max(dp[i][val % m], val);
                }
            }
        }
        cout << dp[n][0] << '\n';
    }
}
