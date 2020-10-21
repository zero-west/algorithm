#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 999999999;

int N, K;
vector<int> doll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    doll.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> doll[i];
    }

    if (K == 1) {
        if (find(doll.begin(), doll.end(), 1) != doll.end()) {
            cout << 1;
            return 0;
        } else {
            cout << -1;
            return 0;
        }
    }

    int p = 0;
    int ret = INF;
    int curCnt = 0;
    for (int q = 0; q < N; q++) {
        if (doll[q] == 1) {
            curCnt++;
        }

        if (curCnt == K) {
            while (curCnt == K) {
                if (doll[p] == 1) curCnt--;
                p++;
            }
            ret = min(ret, q - (p - 1) + 1);
        }
    }
    cout << ((ret != INF) ? ret : -1);
}
