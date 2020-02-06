#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>

using namespace std;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, -1, 0, 1};

int N;
char board[50][50];
int dist[50][50][5];

pair<int, int> starting, ending;
bool flag = false;
deque<pair<pair<int, int>, pair<int, int> > > dq;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    fill(&dist[0][0][0], &dist[49][49][4] + 1, 1e9);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == '#' && !flag) {
                starting = make_pair(i, j);
                flag = true;
                for (int k = 0; k < 4; k++) {
                    dist[i][j][k] = 0;
                    dq.emplace_back(make_pair(make_pair(0, k), make_pair(i, j)));
                }
            } else if (board[i][j] == '#' && flag) {
                ending = make_pair(i, j);
            }
        }
    }
    
    vector<int> resList;
    while (!dq.empty()) {
        auto[info, loc] = dq.front();
        dq.pop_front();
        auto[curDist, curDir] = info;
        auto[curR, curC] = loc;

        if (make_pair(curR, curC) == ending) resList.emplace_back(curDist);
        int nR = curR + dr[curDir];
        int nC = curC + dc[curDir];


        if (nR < 0 || nC < 0 || nR >= N || nC >= N) continue;
        if (board[nR][nC] == '*') continue;
        if (dist[nR][nC][curDir] > curDist) {
            dist[nR][nC][curDir] = curDist;

            if (board[nR][nC] == '!') {
                dq.emplace_back(make_pair(make_pair(curDist + 1, (curDir + 1) % 4), make_pair(nR, nC)));
                dq.emplace_back(make_pair(make_pair(curDist + 1, (curDir - 1)<0? 3: curDir -1), make_pair(nR, nC)));
            }
            dq.emplace_front(make_pair(make_pair(curDist, curDir), make_pair(nR, nC)));
        }
    }

    cout << *(min_element(resList.begin(), resList.end()));
}
