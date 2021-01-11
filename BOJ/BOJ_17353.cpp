# pragma GCC optimize ("O3")
# pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

struct Tree {
    long long lazy, cnt;
};

int N, Q;
vector<int> arr;
vector<Tree> tree;

void init(int node, int start, int end) {
    if (start == end) {
        tree[node].lazy = arr[start];
        return;
    }
    int mid = (start + end) >> 1;
    init(node << 1, start, mid);
    init(node << 1 | 1, mid + 1, end);
}

void update(int node, int start, int end, int left, int right) {
    if (left > end || start > right) return;

    if (left <= start && end <= right) {
        tree[node].lazy += start - left + 1;
        tree[node].cnt++;
        return;
    }

    int mid = (start + end) >> 1;
    update(node << 1, start, mid, left, right);
    update(node << 1 | 1, mid + 1, end, left, right);
}

long long query(int node, int start, int end, int idx) {
    if (start > idx || end < idx) return 0;

    if (start == end) {
        return tree[node].lazy;
    } else {
        int mid = (start + end) >> 1;
        return tree[node].lazy + tree[node].cnt * (idx - start) +
               query(node << 1, start, mid, idx) + query(node << 1 | 1, mid + 1, end, idx);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    arr.resize(N + 1);
    tree.assign(4 * N, {0, 0});
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    init(1, 1, N);

    cin >> Q;
    while (Q--) {
        int a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            update(1, 1, N, b, c);
        } else {
            cin >> b;
            cout << query(1, 1, N, b) << '\n';
        }
    }
}
