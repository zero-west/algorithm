#include <bits/stdc++.h>

using namespace std;


bool can_remove(vector<string> &board, const vector<pair<int, int>> &v, const char &k) {
    if (v[0].first == v[1].first) {             // ㅡ 자 배치
        for (int i = v[0].second + 1; i < v[1].second; i++) {
            if (board[v[0].first][i] != '.') {
                return false;
            }
        }
    } else if (v[0].second == v[1].second) {    // ㅣ자 배치
        for (int i = v[0].first + 1; i < v[1].first; i++) {
            if (board[i][v[0].second] != '.') {
                return false;
            }
        }
    } else {                                    // 대각선 배치
        bool flag1 = true, flag2 = true;    // 세로 선
        for (int i = v[0].first; i <= v[1].first; i++) {
            if (board[i][v[0].second] != k) {
                if (flag1 && board[i][v[0].second] != '.') {
                    flag1 = false;
                }
            }
            if (board[i][v[1].second] != k) {
                if (flag2 && board[i][v[1].second] != '.') {
                    flag2 = false;
                }
            }
        }
        bool flag3 = true, flag4 = true;    // 가로 선
        for (int j = min(v[0].second, v[1].second); j <= max(v[0].second, v[1].second); j++) {
            if (board[v[0].first][j] != k) {
                if (flag4 && board[v[0].first][j] != '.') {
                    flag4 = false;
                }
            }
            if (board[v[1].first][j] != k) {
                if (flag3 && board[v[1].first][j] != '.') {
                    flag3 = false;
                }
            }
        }

        if (flag1 && flag3) return true;
        if (flag2 && flag4) return true;
        return false;
    }
    return true;
}

string solution(int m, int n, vector<string> board) {
    string answer = "";

    map<char, vector<pair<int, int>>> mapping;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.' || board[i][j] == '*') continue;

            if (mapping.count(board[i][j])) {
                mapping[board[i][j]].emplace_back(i, j);
            } else {
                mapping[board[i][j]] = vector<pair<int, int>>{{i, j}};
            }
        }
    }

    while (true) {
        if (mapping.empty()) return answer;

        char delKey = -1;
        for (const auto &[k, v]: mapping) {
            if (can_remove(board, v, k)) {
                answer += k;
                delKey = k;
                break;
            }
        }

        if (delKey == -1) return "IMPOSSIBLE";
        else {
            for (const auto&[r, c] : mapping[delKey]) {
                board[r][c] = '.';
            }
            mapping.erase(delKey);
        }
    }
}
