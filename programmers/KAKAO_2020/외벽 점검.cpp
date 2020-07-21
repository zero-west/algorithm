#include <bits/stdc++.h>

using namespace std;
const int INF = 999999999;

int dp[1 << 15][8], N;
vector<int> my_weak, my_dist;

int solve(int state, int idx) {
    if (state == (1 << my_weak.size()) - 1) return 0;
    if (idx == my_dist.size()) return INF;

    int &ret = dp[state][idx];
    if (ret != -1) return ret;

    ret = INF;

    for (int i = 0; i < my_weak.size(); i++) {
        if (state & (1 << i)) continue;
        int nState = state;

        for (int j = 0; j < my_weak.size(); j++) {
            int flag = (my_weak[j] - my_weak[i] + N) % N;
            // 범위 내 인 경우(비트를 켜준다)
            if (flag <= my_dist[idx]) {
                nState |= 1 << j;
            }
        }
        ret = min(ret, solve(nState, idx + 1) + 1);
    }
    return ret;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    N = n;
    my_weak = weak;
    my_dist = dist;

    sort(my_dist.rbegin(), my_dist.rend());


    memset(dp, -1, sizeof(dp));
    int answer = solve(0, 0);
    if(answer == INF) answer = -1;
    
    return answer;
}
