#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int T;

auto solve(string curPath) {
    vector<int> ret(curPath.length() / 2 + 1, 0);

    stack<pair<int, int>> st;   // parent, cur
    int curIdx = 0;
    for (const char &ch : curPath) {
        if (st.empty()) {
            st.emplace(0, ++curIdx);
        } else if (ch == '0') {
            st.emplace(st.top().second, ++curIdx);
        } else {
            auto[parent, cur] = st.top();
            ret[cur] += 1;
            ret[parent] += ret[cur];
            st.pop();
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int i = 0; i < T; i++) {
        string A, B;
        cin >> A >> B;
        if (solve(A) == solve(B)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}

