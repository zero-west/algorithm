#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> arr;
int maxLen[100001];

bool valid(int length) {
    int idx = 0, curM = 0;
    while (idx < N) {
        if (maxLen[idx] >= length) {
            curM++;
            idx += length;
        } else {
            idx++;
        }
    }
    return curM >= M;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    unordered_multiset<int> ums;
    int p = 0, q = 0;
    while (p < N) {
        if (q >= N || ums.count(arr[q])) {
            maxLen[p] = q - p;
            ums.erase(arr[p++]);
        } else {
            ums.insert(arr[q++]);
        }
    }

    int left = 1, right = N;
    int result = 1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (valid(mid)) {
            left = mid + 1;
            result = max(result, mid);
        } else {
            right = mid - 1;
        }
    }
    cout << result;
}
