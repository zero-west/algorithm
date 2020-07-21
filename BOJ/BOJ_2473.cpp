#include <bits/stdc++.h>

using namespace std;
vector<long long> seq;
int N;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    seq.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }

    long long sumRes = 9999999999999999;
    vector<long long> result;
    sort(seq.begin(), seq.end());

    for (int idx = 0; idx < seq.size() - 2; idx++) {
        long long fixed = seq[idx];
        int p = idx + 1, q = N - 1;

        while (p < q) {
            long long curSum = fixed + seq[p] + seq[q];

            if (llabs(sumRes) > llabs(curSum)) {
                sumRes = curSum;
                result.clear();
                result.emplace_back(fixed);
                result.emplace_back(seq[p]);
                result.emplace_back(seq[q]);
            }

            if (llabs(fixed + seq[p + 1] + seq[q]) > llabs(fixed + seq[p] + seq[q - 1])) {
                q--;
            } else {
                p++;
            }
        }
    }

    sort(result.begin(), result.end());
    for (const auto &k: result) {
        cout << k << ' ';
    }
}
