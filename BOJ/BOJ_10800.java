import java.io.*;
import java.util.*;

public class Main {
    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

    static class Tuple implements Comparable {
        int color, size, idx;

        private Tuple(int color, int size, int idx) {
            this.color = color;
            this.size = size;
            this.idx = idx;
        }

        @Override
        public int compareTo(Object o) {
            Tuple other = (Tuple) o;
            if (this.size != other.size) return Integer.compare(this.size, other.size);
            else return Integer.compare(this.color, other.color);
        }

        public static Tuple create(StringTokenizer tokens, int idx) {
            return new Tuple(Integer.parseInt(tokens.nextToken()) - 1, Integer.parseInt(tokens.nextToken()), idx);
        }
    }

    int N;
    Tuple[] infos;
    int[] colorMap, sizeMap;

    void init() throws Exception {
        N = Integer.parseInt(bufferedReader.readLine());
        infos = new Tuple[N];
        colorMap = new int[N];
        sizeMap = new int[2001];

        for (int i = 0; i < N; i++) {
            StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            infos[i] = Tuple.create(stringTokenizer, i);
        }
    }

    void solve() throws Exception {
        int curSum = 0;
        int[] ans = new int[N];
        Arrays.sort(infos);
        for (int i = 0; i < N; i++) {
            Tuple tuple = infos[i];
            colorMap[tuple.color] += tuple.size;
            sizeMap[tuple.size] += tuple.size;
            curSum += tuple.size;

            if (i == 0 || tuple.size != infos[i - 1].size || tuple.color != infos[i - 1].color) {
                ans[tuple.idx] = curSum - colorMap[tuple.color] - sizeMap[tuple.size] + tuple.size;
            } else {
                ans[tuple.idx] = ans[infos[i - 1].idx];
            }
        }
        for (int k : ans) bufferedWriter.write(k + "\n");
        bufferedWriter.flush();
    }

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.init();
        main.solve();
        main.bufferedReader.close();
        main.bufferedWriter.close();
    }
}
