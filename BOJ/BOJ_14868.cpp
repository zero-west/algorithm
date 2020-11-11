#include <bits/stdc++.h>

using namespace std;

int N, K;
constexpr int dr[4] = {-1, 0, 1, 0};
constexpr int dc[4] = {0, -1, 0, 1};

int cnt, parent[100001], ranking[100001];
int visited[2005][2005];
queue<pair<int, int>> que;

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    int x = getParent(a);
    int y = getParent(b);

    if (x == y) return;

    if (ranking[x] < ranking[y]) {
        parent[x] = y;
    } else {
        parent[y] = x;
        if (ranking[y] == ranking[x]) {
            ranking[x]++;
        }
    }
    cnt++;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for (int i = 1; i <= K; i++) {
        parent[i] = i;

        int r, c;
        cin >> r >> c;
        visited[r][c] = i;
        ranking[i]++;
        que.emplace(r, c);
    }

    int ans = 0;
    while (true) {
        int qSize1 = que.size();
        while (qSize1--) {
            auto[r, c] = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr <= 0 || nc <= 0 || nr > N || nc > N) continue;
                if (visited[nr][nc])
                    unionParent(visited[r][c], visited[nr][nc]);
            }
            que.emplace(r, c);

        }

        if (cnt == K - 1) {
            cout << ans;
            return 0;
        }

        int qSize2 = que.size();
        while (qSize2--) {
            auto[r, c] = que.front();
            que.pop();

            for (int j = 0; j < 4; j++) {
                int nr = r + dr[j];
                int nc = c + dc[j];

                if (nr <= 0 || nc <= 0 || nr > N || nc > N) continue;
                if (visited[nr][nc]) continue;
                visited[nr][nc] = visited[r][c];
                que.emplace(nr, nc);
            }
        }
        ans++;
    }
}
