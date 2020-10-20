#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int N, M;
int destroyed[1000001];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        destroyed[x]++;
        destroyed[y]--;
    }

    int flag = 0;
    int count = 0;

    for (int i = 1; i <= N; i++) {
        flag += destroyed[i];
        if (!flag) count++;
    }

    cout << count;
}
