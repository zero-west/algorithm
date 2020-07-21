#include <bits/stdc++.h>

using namespace std;

int N, M, roomCnt, maxArea, oneDelMax, board[50][50];
int visited[50][50];

int numArea[2500];


const int dr[] = {0, -1, 0, 1};
const int dc[] = {-1, 0, 1, 0};

void bfs(int R, int C, int roomNum) {
    queue<pair<int, int>> que;

    int tmpArea = 1;
    visited[R][C] = roomNum;
    que.emplace(make_pair(R, C));

    while (!que.empty()) {
        auto[curR, curC] = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            if (board[curR][curC] & (1 << i)) continue;

            int nR = curR + dr[i];
            int nC = curC + dc[i];

            if (visited[nR][nC]) continue;
            tmpArea++;
            visited[nR][nC] = roomNum;
            que.emplace(make_pair(nR, nC));
        }
    }

    numArea[roomNum] = tmpArea;
    maxArea = max(maxArea, tmpArea);
}

void solve(int R, int C) {
    int ret = numArea[visited[R][C]];

    int nR, nC;
    for (int i = 0; i < 4; i++) {
        if (board[R][C] & (1 << i)) {
            nR = R + dr[i];
            nC = C + dc[i];

            if (nR < 0 || nC < 0 || nR >= M || nC >= N) continue;
            if (visited[nR][nC] == visited[R][C]) continue;
            oneDelMax = max(oneDelMax, numArea[visited[R][C]] + numArea[visited[nR][nC]]);
        }
    }

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                roomCnt++;
                bfs(i, j, roomCnt);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
           solve(i, j);
        }
    }

    cout << roomCnt << '\n' << maxArea << '\n' << oneDelMax;
}
