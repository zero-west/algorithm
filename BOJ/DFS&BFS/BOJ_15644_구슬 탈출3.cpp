#include <bits/stdc++.h>

using namespace std;

int N, M;
char board[10][10];
int visited[10][10][10][10];

pair<int, int> red, blue, endPoint;
queue<tuple<pair<int, int>, pair<int, int>, vector<char>>> q;
vector<char> emptyVec;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
char dChar[4] = { 'U', 'L', 'D', 'R' };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++) {
			board[i][j] = temp[j];
			if (board[i][j] == 'R')
				red = make_pair(i, j);
			else if (board[i][j] == 'B')
				blue = make_pair(i, j);
			else if (board[i][j] == 'O')
				endPoint = make_pair(i, j);
		}
	}

	visited[red.first][red.second][blue.first][blue.second] = true;
	q.emplace(make_tuple(red, blue, emptyVec));

	while (!q.empty()) {
		auto [a, b, curVec] = q.front();
		auto [rR, rC] = a;
		auto [bR, bC] = b;
		q.pop();

		if (a == endPoint) {
			cout << curVec.size() << '\n';
			for (const auto& c : curVec) {
				cout << c;
			}
			return 0;
		}

		for (int dir = 0; dir < 4; dir++) {
			vector<char> nxtVec = curVec;
			int redR = rR, redC = rC;
			int blueR = bR, blueC = bC;
			bool redflag = true, blueflag = true;
			while (true) {
				int nbR = blueR + dr[dir];
				int nbC = blueC + dc[dir];
				if (board[nbR][nbC] == '#') break;
				else if (board[nbR][nbC] == 'O') {
					blueflag = false;
					blueR = nbR;
					blueC = nbC;
					break;
				} else {
					blueR = nbR;
					blueC = nbC;
				}
			}

			while (true) {
				int nrR = redR + dr[dir];
				int nrC = redC + dc[dir];
				if (board[nrR][nrC] == '#') break;
				else if (board[nrR][nrC] == 'O') {
					redflag = false;
					redR = nrR;
					redC = nrC;
					break;
				} else {
					redR = nrR;
					redC = nrC;
				}
			}

			if ((!redflag) && (!blueflag)) continue;

			int redDist = abs(rR - redR) + abs(rC - redC);
			int blueDist = abs(bR - blueR) + abs(bC - blueC);

			if (redR == blueR && redC == blueC) {
				if (redDist < blueDist) {
					blueR -= dr[dir];
					blueC -= dc[dir];
				} else {
					redR -= dr[dir];
					redC -= dc[dir];
				}
			}

			if (make_pair(blueR, blueC) == endPoint) {
				continue;
			}

			if (visited[redR][redC][blueR][blueC]) continue;
			if (curVec.size() == 10) continue;
			visited[redR][redC][blueR][blueC] = true;
			nxtVec.emplace_back(dChar[dir]);
			q.emplace(make_tuple(make_pair(redR, redC), make_pair(blueR, blueC), nxtVec));
		}
	}

	cout << -1;
	return 0;
}
