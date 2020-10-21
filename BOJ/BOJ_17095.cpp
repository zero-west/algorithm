#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 999999999;

int N;
vector<int> arr;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    if (N == 1) {
        cout << 1;
        return 0;
    }

    int max_idx = 0, min_idx = 0;
    int flag = 0;
    int ret = INF;

    for (int idx = 1; idx < N; idx++) {
        if (arr[idx] >= arr[max_idx])
            max_idx = idx;
        if (arr[idx] <= arr[min_idx])
            min_idx = idx;

        if (flag < arr[max_idx] - arr[min_idx]) {
            ret = abs(max_idx - min_idx) + 1;
            flag = arr[max_idx] - arr[min_idx];
        } else if (flag == arr[max_idx] - arr[min_idx]) {
            ret = min(ret, abs(max_idx - min_idx) + 1);
        }
    }
    cout << ret;
}
