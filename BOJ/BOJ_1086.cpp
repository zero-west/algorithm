#include <bits/stdc++.h>

using namespace std;

int N, K;

string num[15]; // l번째 수
int len[15];    // l 번째 수의 길이
int numMod[15]; // l 번째 수를 K로 나눈 나머지 값
int TENMOD[51]; // 10^l 을 K 로 나눈 나머지 값

long long dp[1 << 15][101];   // dp[state][MOD]: 현재 상태가 state 일때 나머지가 MOD 인 것의 개수

long long gcd_recursion(long long u, long long v) {
    if (v == 0) {
        return u;
    } else {
        return gcd_recursion(v, u % v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        len[i] = num[i].length();
    }
    cin >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < len[i]; j++) {
            numMod[i] = numMod[i] * 10 + (num[i][j] - '0');
            numMod[i] %= K;
        }
    }

    TENMOD[0] = 1;
    for (int i = 1; i <= 50; i++) {
        TENMOD[i] = (TENMOD[i - 1] * 10) % K;
    }

    dp[0][0] = 1;
    for (int p = 0; p < (1 << N); p++) {
        for (int q = 0; q < K; q++) {
            for (int r = 0; r < N; r++) {
                if (p & (1 << r)) continue;
                int nMod = (q * TENMOD[len[r]] + numMod[r]) % K;
                dp[p | (1 << r)][nMod] += dp[p][q];
            }
        }
    }

    long long answer = dp[(1<<N)-1][0];
    if (answer == 0){
        cout << "0/1";
        return 0;
    }
    long long bunmo = 1;
    for (int i = 1; i <= N; i++){
        bunmo *= i;
    }
    long long cur_gcd = gcd_recursion(answer, bunmo);
    answer /= cur_gcd;
    bunmo /= cur_gcd;
    cout << answer << '/' << bunmo;
}
