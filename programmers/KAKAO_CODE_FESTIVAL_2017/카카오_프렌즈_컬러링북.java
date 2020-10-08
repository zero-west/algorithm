import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    static class Pair {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int dR[] = new int[]{-1, 0, 1, 0};
    static int dC[] = new int[]{0, -1, 0, 1};

    public int bfs(int curR, int curC, int m, int n, int[][] picture, boolean[][] visited) {
        int curArea = 0;
        
        Queue<Pair> queue = new ArrayDeque<>();
        queue.offer(new Pair(curR, curC));
        visited[curR][curC] = true;

        while (!queue.isEmpty()) {
            Pair curPair = queue.poll();
            curArea += 1;

            for (int i = 0; i < 4; i++) {
                int nR = curPair.x + dR[i];
                int nC = curPair.y + dC[i];

                if (nR < 0 || nC < 0 || nR >= m || nC >= n) continue;
                if (visited[nR][nC]) continue;
                if (picture[curPair.x][curPair.y] != picture[nR][nC]) continue;

                visited[nR][nC] = true;
                queue.offer(new Pair(nR, nC));
            }
        }
        return curArea;
    }


    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;

        boolean[][] visited = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && picture[i][j] != 0) {
                    numberOfArea++;
                    maxSizeOfOneArea = Integer.max(bfs(i, j, m, n, picture, visited), maxSizeOfOneArea);
                }
            }
        }

        return new int[]{numberOfArea, maxSizeOfOneArea};
    }
}
