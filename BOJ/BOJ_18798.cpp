# pragma GCC optimize ("O3")
# pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<int> arr, fenTree, segTree;

void fen_update(int i, int diff) {
    while (i < N + 1) {
        fenTree[i] += diff;
        i += (i & -i);
    }
}

int count(int i) {
    int ret = 0;
    while (i > 0) {
        ret += fenTree[i];
        i -= (i & -i);
    }
    return ret;
}

void init(int node, int start, int end) {
    if (start == end) {
        segTree[node] = arr[start];
        return;
    }
    int mid = (start + end) >> 1;
    init(node << 1, start, mid);
    init(node << 1 | 1, mid + 1, end);
    segTree[node] = segTree[node << 1] & segTree[node << 1 | 1];
}

void update(int node, int start, int end, int left, int right, int val) {
    if (right < start || end < left) return;
    if ((segTree[node] & val) == val) return;

    if (start == end) {
        if (segTree[node] == K) fen_update(start, -1);
        segTree[node] |= val;
        if (segTree[node] == K) fen_update(start, 1);
        return;
    }

    int mid = (start + end) >> 1;
    update(node << 1, start, mid, left, right, val);
    update(node << 1 | 1, mid + 1, end, left, right, val);
    segTree[node] = segTree[node << 1] & segTree[node << 1 | 1];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    arr.resize(N + 1);
    fenTree.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] == K) {
            fen_update(i, 1);
        }
    }

    segTree.resize(4 * N);
    init(1, 1, N);
    cin >> M;
    while (M--) {
        int a, b, c, d;
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update(1, 1, N, b, c, d);
        } else {
            cin >> b >> c;
            cout << count(c) - count(b - 1) << '\n';
        }
    }
}
