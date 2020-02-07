#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, -1, 0, 1};

int T, N, K, board[8][8], boardTmp[8][8], visited[8][8];
int maxH, tcDepth;
vector<pair<int, int> > mountain[21];
vector<pair<int, int> > emptyVec;


void dfs(int depth, int R, int C) {
    int curR = R, curC = C;
    visited[curR][curC] = 1;
    tcDepth = max(tcDepth, depth);

    for (int k = 0; k < 4; k++) {
        int nR = curR + dr[k];
        int nC = curC + dc[k];

        if (nR < 0 || nC < 0 || nR >= N || nC >= N)continue;
        if (visited[nR][nC]) continue;
        if (boardTmp[nR][nC] >= boardTmp[curR][curC]) continue;

        dfs(depth + 1, nR, nC);
    }
    visited[curR][curC] = 0;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        fill(&mountain[0], &mountain[20] + 1, emptyVec);

        cin >> N >> K;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
                boardTmp[i][j] = board[i][j];
                mountain[board[i][j]].push_back(make_pair(i, j));
            }
        }

        for (int i = 20; i >= 1; i--) {
            if (mountain[i].size() != 0) {
                maxH = i;
                break;
            }
        }

        vector<int> idx(N * N - 1, 0);
        idx.push_back(1);
        tcDepth = 0;

        do {
            int selectR, selectC;
            vector<int>::iterator iter = find(idx.begin(), idx.end(), 1);
            selectR = (iter - idx.begin()) / N;
            selectC = (iter - idx.begin()) % N;

            int tempH = boardTmp[selectR][selectC];
            for (int k = 0; k <= min(K, tempH); k++) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        boardTmp[i][j] = board[i][j];
                    }
                }
                boardTmp[selectR][selectC] -= k;

                for (int s = 0; s < mountain[maxH].size(); s++) {
                    dfs(1, mountain[maxH][s].first, mountain[maxH][s].second);
                }
            }
        } while (next_permutation(idx.begin(), idx.end()));

        cout << '#' << tc << ' ' << tcDepth << '\n';
    }
}
