import java.util.Arrays;

class Solution {
    private static final int INF = 999999999;

    public int solution(int n, int[][] results) {
        int[][] dist = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = (i == j) ? 0 : INF;
            }
        }

        Arrays.stream(results).forEach(arr -> dist[arr[0] - 1][arr[1] - 1] = 1);

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < n; i++) {
            int curWin = 0, curLose = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] != INF && i != j) curWin++;
                if (dist[j][i] != INF && i != j) curLose++;
            }

            if (curWin + curLose == n - 1) answer++;
        }
        return answer;
    }
}