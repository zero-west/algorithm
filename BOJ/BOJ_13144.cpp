#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int N, arr[100001];
unordered_set<int> us;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long result = 0;
    int p = 0, q = 0;
    while (p < N) {
        if (q < N && us.count(arr[q]) == 0) {
            us.insert(arr[q++]);
            result += 1LL * (q - p);
        } else {
            us.erase(arr[p++]);
        }
    }
    cout << result;
}
