#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int N, B, W, result;
string stone;
unordered_map<char, int> mapping;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> B >> W;
    cin >> stone;

    int p = 0, q = 0;
    while (q < N) {
        mapping[stone[q++]] += 1;

        while (mapping['B'] > B) {
            mapping[stone[p++]] -= 1;
        }

        if(mapping['B'] <= B && mapping['W'] >=W) result = max(result, q-p);
    }
    cout << result;
}
