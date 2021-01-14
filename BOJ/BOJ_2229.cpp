#include <bits/stdc++.h>

using namespace std;

int N;
int scores[1010], dp[1010];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int curMax = 0;
    for (int i = 1; i <= N; i++) {
        cin >> scores[i];

        for (int j = i - 1; j >= 1; j--) {
            curMax = max(curMax, abs(scores[i] - scores[j]) + dp[j - 1]);
        }
        dp[i] = curMax;
    }
    cout << dp[N];
}
