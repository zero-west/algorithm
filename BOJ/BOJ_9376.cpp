#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 99999999;
constexpr int dr[4] = {-1, 0, 1, 0};
constexpr int dc[4] = {0, -1, 0, 1};

char board[102][102];
int minDist[102][102][3];   // r,c, idx(0~2)
pair<int, int> manList[3];


int T, w, h;

void zeroOneBfs(pair<int, int> start, int idx) {
    deque<pair<int, int>> dq;
    dq.emplace_front(start);
    minDist[start.first][start.second][idx] = 0;

    while (!dq.empty()) {
        auto[r, c]=  dq.front();
        int curDist = minDist[r][c][idx];
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr > h + 1 || nc < 0 || nc > w + 1 || board[nr][nc] == '*') continue;
            if (minDist[nr][nc][idx] != MAX) continue;

            // 그냥 길이거나 빈공간이면
            if (board[nr][nc] == '.' || !board[nr][nc]) {
                minDist[nr][nc][idx] = curDist;
                dq.emplace_front(make_pair(nr, nc));
            } else if (board[nr][nc] == '#') {
                minDist[nr][nc][idx] = curDist + 1;
                dq.emplace_back(make_pair(nr, nc));
            }
        }

    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> h >> w;
        fill(&minDist[0][0][0], &minDist[101][101][2] + 1, MAX);
        fill(&board[0][0], &board[101][101], 0);
        
        int p = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> board[i][j];

                if (board[i][j] == '$') {
                    board[i][j] = '.';
                    manList[p++] = make_pair(i, j);
                }

            }
        }
        for (int i = 0; i < 3; i++) {
            zeroOneBfs(manList[i], i);
        }

        int tcResult = MAX;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (board[i][j] == '*') continue;
                int tmp = minDist[i][j][0] + minDist[i][j][1] + minDist[i][j][2];
                if (board[i][j] == '#') {
                    tmp -= 2;
                }
                tcResult = min(tcResult, tmp);
            }
        }

        cout << tcResult << '\n';
    }
}
