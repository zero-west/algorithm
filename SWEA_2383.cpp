#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
int T, N;
 
int board[10][10];
 
vector<pair<int, pair<int, int> > > stairList;
vector<pair<int, int> > personList;
vector<vector<int> > settingSet;
queue<int> stairQue[2];
queue<pair<int, bool> > entranceQue[2];
 
inline int getDist(pair<int, int> person, pair<int, int> stair) {
    return abs(person.first - stair.first) + abs(person.second - stair.second);
}
 
queue<int> emptyQue;
queue<pair<int, bool> > emptyQue2;
 
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int tcRes = 1e9;
        stairList.clear();
        personList.clear();
        settingSet.clear();
        for (int i = 0; i <= 1; i++) {
            entranceQue[i] = emptyQue2;
            stairQue[i] = emptyQue;
        }
        cin >> N;
 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
                if (board[i][j] == 1) {
                    personList.push_back(make_pair(i, j));
                }
                else if (board[i][j] >= 2)
                    stairList.push_back(make_pair(board[i][j], make_pair(i, j)));
            }
        }
 
        settingSet.push_back(vector<int>(1, 0));
        settingSet.push_back(vector<int>(1, 1));
 
        for (int idx = 1; idx < personList.size(); idx++) {
            vector<vector<int> > tmpSetting;
            for (vector<vector<int> >::iterator iter = settingSet.begin(); iter != settingSet.end(); iter++) {
                vector<int> curVec = *iter;
                vector<int> nxtVec = curVec;
                curVec.push_back(0);
                nxtVec.push_back(1);
                tmpSetting.push_back(curVec);
                tmpSetting.push_back(nxtVec);
            }
            settingSet = tmpSetting;
        }
 
        for (vector<vector<int> >::iterator iter = settingSet.begin(); iter != settingSet.end(); iter++) {
            vector<int> curSet = *iter;
            if ((curSet.size() != personList.size())) continue;
 
            deque<int> distList[2];
            for (int i = 0; i < personList.size(); i++) {
                distList[curSet[i]].push_back(getDist(personList[i], stairList[curSet[i]].second));
 
            }
             
            for (int i = 0; i < 2; i++) {
                sort(distList[i].begin(), distList[i].end());
            }
 
            int finishCnt = 0;
            for (int sec = 1; sec <= 1000; sec++) {
                for (int i = 0; i < 2; i++) {
                    if (!distList[i].empty() && *distList[i].begin() == sec) {
                        deque<int>::iterator starting = lower_bound(distList[i].begin(), distList[i].end(), sec);
                        deque<int>::iterator ending = upper_bound(distList[i].begin(), distList[i].end(), sec);
 
                        for (deque<int>::iterator upIter = starting; upIter != ending; upIter++) {
                            entranceQue[i].push(make_pair(sec, false));
                        }
                        distList[i].erase(starting, ending);
                    }
 
                    int q_size1 = stairQue[i].size();
                    while (q_size1--) {
                        int fro = stairQue[i].front();
                        stairQue[i].pop();
 
                        if (fro == stairList[i].first) {
                            finishCnt++;
                            continue;
                        }
                        else {
                            fro++;
                            stairQue[i].push(fro);
                        }
                    }
                    int q_size2 = entranceQue[i].size();
                    while (q_size2--) {
                        pair<int, bool> fro = entranceQue[i].front();
                        entranceQue[i].pop();
 
                        if (fro.second == false) {
                            fro.second = true;
                            entranceQue[i].push(fro);
                            continue;
                        }
 
                        if (stairQue[i].size() < 3) {
                            stairQue[i].push(1);
                        }
                        else {
                            entranceQue[i].push(fro);
                        }
                    }
                }
 
                if (finishCnt == personList.size()) {
                    tcRes = min(tcRes, sec);
                    break;
                }
            }
        }
        cout << '#' << tc << ' ' << tcRes << '\n';
    }
}
