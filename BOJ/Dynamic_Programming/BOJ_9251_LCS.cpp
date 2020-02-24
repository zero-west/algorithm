#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

string a, b, str1 = " ", str2 = " ";

int solve(int m, int n) {
    if (m == 0 || n == 0) return 0;

    int &ret = dp[m][n];
    if (ret != -1) return ret;

    if (str1[m] == str2[n]) {
        ret = 1 + solve(m - 1, n - 1);
    } else {
        ret = max(solve(m - 1, n), solve(m, n - 1));
    }
    return ret;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;

    str1 += a;
    str2 += b;

    memset(dp, -1, sizeof(dp));
    int answer = solve(a.size(), b.size());
    cout << answer;
}
