#include <bits/stdc++.h>

using namespace std;

int D;

constexpr long long MOD = 1000000007;

unordered_set<int> adj[8] = {
        unordered_set<int>{1, 2},
        unordered_set<int>{0, 2, 3},
        unordered_set<int>{0, 1, 3, 4},
        unordered_set<int>{1, 2, 4, 5},
        unordered_set<int>{2, 3, 5, 7},
        unordered_set<int>{3, 4, 6},
        unordered_set<int>{5, 7},
        unordered_set<int>{4, 6}
};

long long dp[8][100001];

long long solve(int cur, int depth) {
    long long &ret = dp[cur][depth];

    if (ret != -1) return ret;
    if (depth == D - 1) {
        if(adj[cur].find(0) != adj[cur].end()) return 1;
        else return 0;
    }

    ret = 0;
    for (const auto &nxt: adj[cur]) {
        ret += solve(nxt, depth + 1);
        ret %= MOD;
    }
    return ret;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> D;

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);
}
