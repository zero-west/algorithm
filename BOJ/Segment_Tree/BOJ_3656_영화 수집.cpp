#include <bits/stdc++.h>

using namespace std;

int T, n, m;
long long arr[200001], tree[800004];

long long query(int starting, int ending, int node, int nodeL, int nodeR) {
    if (ending < nodeL || nodeR < starting) return 0;
    if (starting <= nodeL && nodeR <= ending) return tree[node];

    int mid = (nodeL + nodeR) / 2;
    return query(starting, ending, 2 * node, nodeL, mid)
           + query(starting, ending, 2 * node + 1, mid + 1, nodeR);
}

void update(int nodeL, int nodeR, int node, int idx, int diff) {
    if (!(nodeL<=idx && idx<=nodeR)) return;
    tree[node] += diff;
    if (nodeL != nodeR) {
        int mid = (nodeL + nodeR) / 2;
        update(nodeL, mid, 2 * node, idx, diff);
        update(mid + 1, nodeR, 2 * node + 1, idx, diff);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--) {
        cin >> n >> m;
        fill(&arr[0], &arr[n+1]+1,0);
        fill(&tree[0], &tree[4*(n+m+1)]+1,0);

        // init
        for (int i = m + 1; i <= n + m; i++) {
            update(1, n + m, 1, i, 1);
            arr[i - m] = i;   // location
        }

        int idx = m;
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            cout << query(1, arr[num] - 1, 1, 1, n + m) << ' ';
            update(1, n + m, 1, arr[num], -1);
            arr[num] = idx--;
            update(1, n + m, 1, arr[num], 1);
        }

        cout << '\n';
    }
    return 0;
}
