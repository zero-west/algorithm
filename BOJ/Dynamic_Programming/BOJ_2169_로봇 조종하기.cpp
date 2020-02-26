#include <bits/stdc++.h>

using namespace std;

const long long INIT = -99999999999999;

const int dr[3] = {1, 0, 0};
const int dc[3] = {0, -1, 1};

int N, M;
long long board[1001][1001];
long long dp[1001][1001][3];
bool visited[1001][1001];

long long solve(int R, int C, int curDir) {
    if (R == N && C == M) return board[N][M];

    long long &ret = dp[R][C][curDir];

    if (ret != INIT) return ret;

    for (int i = 0; i < 3; i++) {
        int nR = R + dr[i];
        int nC = C + dc[i];

        if (nR <= 0 || nC <= 0 || nR > N || nC > M) continue;
        if (visited[nR][nC]) continue;

        visited[nR][nC] = true;
        ret = max(ret, solve(nR, nC, i) + board[R][C]);
        visited[nR][nC] = false;
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];

            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = INIT;
            }
        }
    }

    visited[1][1] = true;
    cout << solve(1, 1, 0);
}
