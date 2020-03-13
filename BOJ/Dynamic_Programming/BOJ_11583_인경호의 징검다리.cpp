#include <bits/stdc++.h>

using namespace std;

long long T, N, K, tcRes, INF = 999999999999;
vector<long long> seq;
vector<pair<long long, long long>> info;
long long cache[100001][2];	// 인덱스마다 2개수최소, 5개수 최소

pair<long long, long> solve(int cur) {
	auto [curTwo, curFive] = info[cur];

	if (cur == 0) {
		return make_pair(curTwo, curFive);
	}

	long long& ret2 = cache[cur][0];
	long long& ret5 = cache[cur][1];

	if (ret2 != -1 && ret5 != -1) return make_pair(ret2, ret5);
	else if (ret2 != -1) {
		ret5 = INF;
		for (int k = 1; k <= K; k++) {
			if (cur - k < 0) break;
			ret5 = min(ret5, solve(cur - k).second + curFive);
		}
	}	else if (ret5 != -1) {
		ret2 = INF;
		for (int k = 1; k <= K; k++) {
			if (cur - k < 0) break;
			ret2 = min(ret2, solve(cur - k).first + curTwo);
		}
	}	else {
		ret2 = INF;
		ret5 = INF;
		for (int k = 1; k <= K; k++) {
			if (cur - k < 0) break;
			ret2 = min(ret2, solve(cur - k).first + curTwo);
			ret5 = min(ret5, solve(cur - k).second + curFive);
		}
	}
	return make_pair(ret2, ret5);
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N >> K;
		tcRes = 99999999;
		seq.resize(N);
		info.clear();

		for (int i = 0; i < N; i++) {
			cin >> seq[i];
			long long cur = seq[i];
			long long sCnt = 0, fCnt = 0;

			while (true) {
				if (cur % 2 == 0 || cur % 5 == 0) {
					if (cur % 2 == 0) {
						sCnt++;
						cur /= 2;
					}
					if (cur % 5 == 0) {
						fCnt++;
						cur /= 5;
					}
				} else {
					info.emplace_back(make_pair(sCnt, fCnt));
					break;
				}
			}
		}
		memset(cache, -1, sizeof(cache));
		pair<long long, long long> res = solve(N - 1);
		cout << min(res.first, res.second) << '\n';
	}
}
