#include <bits/stdc++.h>

using namespace std;

int N, T, M, L;
int dp[101][10001];

vector<tuple<int, int, int>> adj[101];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> T >> M >> L;

    for (int i = 0; i < L; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a].emplace_back(b, c, d);
        adj[b].emplace_back(a, c, d);
    }

    fill(&dp[0][0], &dp[100][10000], 1e9);

    priority_queue<tuple<int, int, int>> pq;
    pq.emplace(0, T, 1);
    dp[1][T] = 0;

    while (!pq.empty()) {
        auto[curMoney, remainTime, cur] = pq.top();
        pq.pop();
        curMoney *= -1;

        if (dp[cur][remainTime] < curMoney) continue;

        for (const auto &info: adj[cur]) {
            auto[nxt, edgeTime, edgeMoney] = info;

            if (remainTime - edgeTime < 0 || curMoney + edgeMoney > M) continue;
            if (dp[nxt][remainTime - edgeTime] > curMoney + edgeMoney) {
                dp[nxt][remainTime - edgeTime] = curMoney + edgeMoney;
                pq.emplace(-dp[nxt][remainTime - edgeTime], remainTime - edgeTime, nxt);
            }
        }
    }

    int ret = *min_element(&dp[N][0], &dp[N][T] + 1);
    cout << ((ret != 1e9) ? ret : -1);
}
