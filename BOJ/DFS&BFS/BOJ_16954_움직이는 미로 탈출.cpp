#include <iostream>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

vector<vector<char>> board, sec[10];
deque<pair<pair<int, int>, int>> dq;
queue<pair<pair<int, int>, int>> que;

const int dr[] = {0, 0, 0, -1, -1, -1, 1, 1, 1};
const int dc[] = {0, 1, -1, 0, -1, 1, 0, 1, -1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    board.assign(8, vector<char>(8, '.'));
    fill(&sec[0], &sec[9] + 1, board);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
            if (board[i][j] == '#')
                dq.emplace_front(make_pair(make_pair(i, j), 0));
        }
    }

    while (true) {
        int dq_size = dq.size();
        if (dq_size == 0) break;

        while (dq_size--) {
            auto[loc, time] = dq.front();
            auto[curR, curC] = loc;
            dq.pop_front();

            sec[time][curR][curC] = '#';

            int nR = curR + 1;
            int nC = curC;

            if (nR >= 8) continue;

            sec[time + 1][nR][nC] = '#';
            dq.emplace_back(make_pair(make_pair(nR, nC), time + 1));
        }
    }

    que.emplace(make_pair(make_pair(7, 0), 0));

    while (!que.empty()) {
        auto[loc, time] =que.front();
        que.pop();

        if(time==8){
            cout << 1;
            return 0;
        }

        auto[curR, curC] = loc;
        if(curR==0 || curC==7){
            cout << 1;
            return 0;
        }
        for (int i = 0; i < 9; i++) {
            int nR = curR + dr[i];
            int nC = curC + dc[i];

            if (nR < 0 || nC < 0 || nR >= 8 || nC >= 8) continue;
            if(sec[time][nR][nC]=='#') continue;
            if(sec[time+1][nR][nC]=='#') continue;
            que.emplace(make_pair(make_pair(nR,nC),time+1));
        }
    }

    cout << 0;
    return 0;
}
