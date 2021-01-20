#include <bits/stdc++.h>

using namespace std;

int N, T, P, res;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> T >> P;

    int sum = 0, cnt = 0;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        int cur;
        cin >> cur;
        sum += cur;
        pq.emplace(cur);
        cnt++;

        while (!pq.empty() && sum > T) {
            sum -= pq.top();
            pq.pop();
            cnt--;
        }
        if (sum > T) break;
        res = max(res, cnt);
        sum += P;
    }

    cout << res;
}
