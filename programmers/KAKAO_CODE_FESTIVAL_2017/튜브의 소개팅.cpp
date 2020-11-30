#include <bits/stdc++.h>

using namespace std;

queue<tuple<int, int, int>> pq;
long dp[51][51][2501];

vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
    const int dr[] = {-1, 0, 1, 0};
    const int dc[] = {0, -1, 0, 1};
    const long INF = 2e10;

    fill(&dp[0][0][0], &dp[m][n][m * n] + 1, INF);
    dp[0][0][0] = 0;

    pq.emplace(0, 0, 0);
    while (!pq.empty()) {
        auto[curDist, curR, curC] = pq.front();
        pq.pop();

        if (curDist > m * n) continue;
        for (int k = 0; k < 4; k++) {
            int nR = curR + dr[k];
            int nC = curC + dc[k];

            if (nR < 0 || nC < 0 || nR >= m || nC >= n) continue;
            if (time_map[nR][nC] == -1) continue;

            long nCost = time_map[nR][nC] + dp[curR][curC][curDist];
            if (nCost > s || dp[nR][nC][curDist + 1] <= nCost) continue;

            dp[nR][nC][curDist + 1] = nCost;
            pq.emplace((curDist + 1), nR, nC);
        }
    }

    for (int i = m + n - 2; i <= m * n; i++) {
        if (dp[m - 1][n - 1][i] != INF) {
            return vector<int>{i, (int) dp[m - 1][n - 1][i]};
        }
    }
}
