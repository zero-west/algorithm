#include <bits/stdc++.h>

using namespace std;

int T, D, W, K, tcRes;

int board[13][20], boardTmp[13][20];
vector<int> idx;
vector<vector<int> > tmpH;

void insertMed(int rIndex, int m_type) {
    for (int i = 0; i < W; i++) {
        boardTmp[rIndex][i] = m_type;
    }
}

bool checker() {
    int curR, curC;
    int maxi;
    bool flag = true;
    bool maxiFlag;

    for (int index = 0; index < W; index++) {
        curR = 0;
        curC = index;
        maxi = 1;
        maxiFlag = false;

        while (true) {
            int nR = curR + 1;
            if (nR >= D) {
                flag = flag && maxiFlag;
                break;
            }
            if (boardTmp[curR][curC] == boardTmp[nR][curC]) {
                maxi++;
            } else {
                maxi = 1;
            }

            curR = nR;

            if (maxi >= K) {
                maxiFlag = true;
            }
        }
    }
    return flag;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        bool tcFlag = false;
        tcRes = 0;
        cin >> D >> W >> K;

        for (int i = 0; i < D; i++) {
            for (int j = 0; j < W; j++) {
                cin >> board[i][j];
                boardTmp[i][j] = board[i][j];
            }
        }

        bool firstCheck = checker();
        if (firstCheck) {
            cout << '#' << tc << ' ' << 0 << '\n';
            continue;
        }

        for (int i = 1; i <= K; i++) {
            idx.assign(D - i, 0);
            for (int j = 0; j < i; j++) {
                idx.push_back(1);
            }

            do {
                tmpH.clear();

                vector<int> selectH;
                for (int k = 0; k < D; k++) {
                    if (idx[k]) {
                        selectH.push_back(k);
                    }
                }

                // SAVE FOR RECOVER
                for (int s = 0; s < selectH.size(); s++) {
                    vector<int> tmp;
                    for (int k = 0; k < W; k++) {
                        tmp.push_back(boardTmp[selectH[s]][k]);
                    }
                    tmpH.push_back(tmp);
                }

                // INSERT
                for (int s = 0; s < selectH.size(); s++) {
                    insertMed(selectH[s], 0);
                }

                // CHECK
                bool checking = checker();
                if (checking) {
                    tcFlag = true;
                    break;
                }

                // RECOVER
                for (int s = 0; s < selectH.size(); s++) {
                    for (int k = 0; k < W; k++) {
                        boardTmp[selectH[s]][k] = tmpH[s][k];
                    }
                }

                // INSERT
                for (int s = 0; s < selectH.size(); s++) {
                    insertMed(selectH[s], 1);
                }

                // CHECK
                bool checking2 = checker();
                if (checking2) {
                    tcFlag = true;
                    break;
                }

                // RECOVER
                for (int s = 0; s < selectH.size(); s++) {
                    for (int k = 0; k < W; k++) {
                        boardTmp[selectH[s]][k] = tmpH[s][k];
                    }
                }

            } while (next_permutation(idx.begin(), idx.end()));

            if (tcFlag) {
                tcRes = i;
                break;
            }
        }
        cout << '#' << tc << ' ' << tcRes << '\n';
    }
}
