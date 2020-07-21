#include <bits/stdc++.h>

using namespace std;

int maxWhite, maxBlack;
int N, board[10][10];
bool visited[10][10];

vector<pair<int, int> > blackList;
vector<pair<int, int> > whiteList;

void dfs1(int idx, int depth) {
    maxWhite = max(maxWhite, depth);
    if (idx == whiteList.size())
        return;

    bool visitedTmp[10][10]; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visitedTmp[i][j] = visited[i][j];
        }
    }

    for (int i = idx + 1; i < whiteList.size(); i++) {
        int R = whiteList[i].first;
        int C = whiteList[i].second;

        if (!visited[R][C]) {
            for (int k = 0; k < N; k++) {
                int selectR = k;
                int selectC = k - (R - C);

                if (!(selectR < 0 || selectC < 0 || selectR >= N || selectC >= N))
                    visited[selectR][selectC] = true;

                selectR = k;
                selectC = (R + C) - k;

                if (!(selectR < 0 || selectC < 0 || selectR >= N || selectC >= N))
                    visited[selectR][selectC] = true;
            }
            
            dfs1(i, depth + 1);

            for (int p = 0; p < N; p++) {
                for (int q = 0; q < N; q++) {
                    visited[p][q] = visitedTmp[p][q];
                }
            }
        }
    }
}

void dfs2(int idx, int depth) {
    maxBlack = max(maxBlack, depth);
    if (idx == blackList.size())
        return;

    bool visitedTmp[10][10];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visitedTmp[i][j] = visited[i][j];
        }
    }

    for (int i = idx + 1; i < blackList.size(); i++) {
        int R = blackList[i].first;
        int C = blackList[i].second;

        if (!visited[R][C]) {
            for (int k = 0; k < N; k++) {
                int selectR = k;
                int selectC = k - (R - C);

                if (!(selectR < 0 || selectC < 0 || selectR >= N || selectC >= N))
                    visited[selectR][selectC] = true;

                selectR = k;
                selectC = (R + C) - k;

                if (!(selectR < 0 || selectC < 0 || selectR >= N || selectC >= N))
                    visited[selectR][selectC] = true;
            }

            dfs2(i, depth + 1);

            for (int p = 0; p < N; p++) {
                for (int q = 0; q < N; q++) {
                    visited[p][q] = visitedTmp[p][q];
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                if ((i + j) % 2 == 0) {
                    whiteList.push_back(make_pair(i, j));
                } else {
                    blackList.push_back(make_pair(i, j));
                }
            }
        }
    }

    dfs1(-1, 0);
    dfs2(-1, 0);
    cout << maxWhite + maxBlack;
    return 0;
}
