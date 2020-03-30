# pragma GCC optimize ("O3")
# pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

struct Query {
    int idx, s, e;
};

vector<Query> query;
int N, M, sqrtN;
vector<int> arr, tree, sortedArr;

long long result;
vector<long long> ans;


bool cmp(const Query &q1, const Query &q2) {
    return make_tuple(q1.s / sqrtN, q1.e, q1.idx) < make_tuple(q2.s / sqrtN, q2.e, q2.idx);
}

int count(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(int i, int diff) {
    while (i < tree.size()) {
        tree[i] += diff;
        i += (i & -i);
    }
}

void add_right(int num) {
    result += count(N + 1) - count(num);
    update(num, 1);
}

void add_left(int num) {
    result += count(num - 1);
    update(num, 1);
}

void erase_right(int num) {
    result -= count(N + 1) - count(num);
    update(num, -1);
}

void erase_left(int num) {
    result -= count(num - 1);
    update(num, -1);
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    sqrtN = sqrt(N);

    arr.resize(N + 1);
    tree.assign(4 * N, 0);
    query.resize(M);
    ans.resize(M);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sortedArr.emplace_back(arr[i]);
    }

    sort(sortedArr.begin(), sortedArr.end());
    sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());

    for (int i = 1; i <= N; i++) {
        arr[i] = lower_bound(sortedArr.begin(), sortedArr.end(), arr[i]) - sortedArr.begin() + 1;
    }

    for (int i = 0; i < M; i++) {
        cin >> query[i].s >> query[i].e;
        query[i].idx = i;
    }

    sort(query.begin(), query.end(), cmp);

    int start = query[0].s, end = query[0].e;
    for (int i = start; i <= end; i++) {
        add_right(arr[i]);
    }
    ans[query[0].idx] = result;

    for (int i = 1; i < M; i++) {
        while (start > query[i].s) {
            --start;
            add_left(arr[start]);
        }
        while (end < query[i].e) {
            end++;
            add_right(arr[end]);
        }
        while (start < query[i].s) {
            erase_left(arr[start]);
            start++;
        }
        while (end > query[i].e) {
            erase_right(arr[end]);
            end--;
        }

        ans[query[i].idx] = result;
    }

    for (int i = 0; i < M; i++) {
        cout << ans[i] << '\n';
    }
}
