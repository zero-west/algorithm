# pragma GCC optimize ("O3")
# pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr, A, tree;
vector<int> parent;

void update(int i, int diff) {
    while (i < N + 1) {
        tree[i] += diff;
        i += (i & -i);
    }
}

int count(int i) {
    int ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= (i & -i);
    }
    return ret;
}

int getParent(int cur) {
    if (parent[cur] == cur) return cur;
    return parent[cur] = getParent(parent[cur]);
}

void unionParent(int a, int b) {
    int x = getParent(a);
    int y = getParent(b);

    if (x == y)return;

    if (x <= y) {
        parent[x] = y;
    } else {
        parent[y] = x;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    arr.assign(N + 1, 0);
    parent.resize(N + 2);
    A.resize(N + 1);
    tree.assign(N + 2, 0);

    for (int i = 1; i <= N+1; i++) {
        parent[i] = i;
        update(i, 1);
    }

    for (int i = 1; i <= N; i++) {
        cin >> A[i];

        if (A[i] == 0) {
            int curIdx = getParent(1);
            arr[curIdx] = i;
            update(curIdx, -1);
            unionParent(1, curIdx + 1);
            continue;
        }

        int lo = 1, hi = N;

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;

            if (count(mid) == A[i]) {
                int curIdx = getParent(mid + 1);
                arr[curIdx] = i;
                update(curIdx, -1);
                unionParent(mid + 1, curIdx + 1);
                break;
            } else if (count(mid) > A[i]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << '\n';
    }
}
