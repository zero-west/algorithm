#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

int N, cost[15][15];
bool visited[15][1 << 15][10];

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &cost[i][j]);
        }
    }

    queue<tuple<int, int, int>> que;
    visited[0][1][0] = true;
    que.emplace(make_tuple(0, 1, 0));

    int answer = 0;
    while (!que.empty()) {
        int q_size = que.size();
        while (q_size--) {
            auto[cur, state, maxCost] = que.front();
            que.pop();
            for (int i = 0; i < N; i++) {
                if (state & (1 << i)) continue;
                if (cost[cur][i] < maxCost) continue;
                if (visited[i][state | (1 << i)][cost[cur][i]]) continue;
                visited[i][state | (1 << i)][cost[cur][i]] = true;
                que.emplace(make_tuple(i, state | (1 << i), cost[cur][i]));
            }
        }
        answer++;
    }

    printf("%d", answer);
}
