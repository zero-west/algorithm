class Solution {
    static final int MOD = 20170805;

    static class Pair {
        long fromLeft, fromUp;

        Pair(long x, long y) {
            this.fromLeft = x;
            this.fromUp = y;
        }
    }

    public int solution(int m, int n, int[][] cityMap) {
        Pair[][] dp = new Pair[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = new Pair(0L, 0L);
            }
        }
        dp[0][0] = new Pair(1, 1);
        for (int i = 1; i < n; i++) {
            if (cityMap[0][i - 1] == 1) break;
            dp[0][i].fromLeft = 1L;
        }

        for (int i = 1; i < m; i++) {
            if (cityMap[i - 1][0] == 1) break;
            dp[i][0].fromUp = 1L;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (cityMap[i - 1][j] == 0)
                    dp[i][j].fromUp = (dp[i - 1][j].fromLeft + dp[i - 1][j].fromUp) % MOD;
                else if (cityMap[i - 1][j] == 1)
                    dp[i][j].fromUp = 0L;
                else if (cityMap[i - 1][j] == 2)
                    dp[i][j].fromUp = dp[i - 1][j].fromUp;

                if (cityMap[i][j - 1] == 0)
                    dp[i][j].fromLeft = (dp[i][j - 1].fromLeft + dp[i][j - 1].fromUp) % MOD;
                else if (cityMap[i][j - 1] == 1)
                    dp[i][j].fromLeft = 0L;
                else if (cityMap[i][j - 1] == 2)
                    dp[i][j].fromLeft = dp[i][j - 1].fromLeft;
            }
        }
        return (int) ((dp[m - 1][n - 1].fromLeft + dp[m - 1][n - 1].fromUp) % MOD);
    }
}
