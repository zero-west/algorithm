#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[5000];

bool flag(int k) {
    int curMin = arr[0], curMax = arr[0], count = 1;
    for (int i = 1; i < N; i++) {
        curMin = min(curMin, arr[i]);
        curMax = max(curMax, arr[i]);
        if (curMax - curMin <= k) continue;

        curMax = arr[i];
        curMin = arr[i];
        count++;
    }
    return count <= M;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int result = 1e9;
    int lo = 0, hi = 10000;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (flag(mid)) {
            hi = mid - 1;
            result = min(result, mid);
        } else {
            lo = mid + 1;
        }
    }
    cout << result;
}
