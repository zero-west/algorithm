#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;

int N;

bool checker(vector<int> &weak) {
    for (const auto &w : weak) {
        if (!visited[w]) return false;
    }
    return true;
}

void going(int location, int power) {
    int curLoc = location;
    int curPow = power + 1;

    while (curPow) {
        int tmpLoc = curLoc % N;
        visited[tmpLoc] = true;

        curLoc++;
        curPow--;
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    N = n;
   
    bool flag = false;
    visited.assign(n + 1, false);

    vector<int> tmpDist = dist;
    sort(tmpDist.begin(), tmpDist.end());

    int weak_size = weak.size();
    int dist_size = tmpDist.size();

    for (int cnt = 1; cnt <= dist_size; cnt++) {
        vector<int> distSelecting;
        vector<vector<int>> weakSelecting;

        // 그리디 하게 가장 큰 dist 를 가진 녀석들로 cnt 개 고른다.
        for (int i = dist_size - cnt; i < dist_size; i++) {
            distSelecting.emplace_back(tmpDist[i]);
        }

        // 어느 위치에서 출발할 지 조합 구현
        vector<int> idx2(weak_size - cnt, 0);
        for (int k = 0; k < cnt; k++) {
            idx2.emplace_back(1);
        }
        do {
            vector<int> selecting;
            for (int i = 0; i < idx2.size(); i++) {
                if (idx2[i]) {
                    selecting.emplace_back(weak[i]);
                }
            }
            weakSelecting.emplace_back(selecting);
        } while (next_permutation(idx2.begin(), idx2.end()));


        // distSelecting 의 순열을 구하면서 위치 조합
        do {
            for (int q = 0; q < weakSelecting.size(); q++) {
                vector<int> curWeak = weakSelecting[q];
                fill(visited.begin(), visited.end(), false);

                for (int r = 0; r < cnt; r++) {
                    going(curWeak[r], distSelecting[r]);
                }
                flag = checker(weak);
                if (flag) {
                    return cnt;
                }
            }
        } while (next_permutation(distSelecting.begin(), distSelecting.end()));
    }
    return -1;
}
