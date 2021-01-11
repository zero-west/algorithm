import java.io.*;
import java.util.*;

public class Main {
    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

    static class FenwickTree {
        long[] arr;

        public FenwickTree(int N) {
            this.arr = new long[N + 1];
        }

        void update(int i, int val) {
            for (int k = i; k < arr.length; k |= (k + 1)) {
                arr[k] += val;
            }
        }

        long getVal(int i) {
            long ans = 0;
            for (int k = i; k >= 0; k -= (k & (k + 1)) - 1) {
                ans += arr[k];
            }
            return ans;
        }
    }

    static class OrderingTree {
        int[] start;
        int[] end;
        int num;

        public OrderingTree(int N) {
            start = new int[N + 1];
            end = new int[N + 1];
        }

        void orderingDfs(int v, int p, List<Integer>[] adj) {
            start[v] = ++num;
            for (int nxt : adj[v]) {
                if (nxt == p) continue;
                orderingDfs(nxt, v, adj);
            }
            end[v] = num;
        }
    }

    int N, M;
    int[] salaries;
    List<Integer>[] adj;

    FenwickTree fenwickTree;
    OrderingTree orderingTree;

    void init() throws Exception {
        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        N = Integer.parseInt(stringTokenizer.nextToken());
        M = Integer.parseInt(stringTokenizer.nextToken());
        salaries = new int[N + 1];
        adj = new List[N + 1];
        for (int i = 0; i <= N; i++) {
            adj[i] = new ArrayList<>();
        }

        salaries[1] = Integer.parseInt(bufferedReader.readLine());
        for (int i = 2; i <= N; i++) {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            salaries[i] = Integer.parseInt(stringTokenizer.nextToken());
            adj[Integer.parseInt(stringTokenizer.nextToken())].add(i);
        }
        fenwickTree = new FenwickTree(N);
        orderingTree = new OrderingTree(N);
        orderingTree.orderingDfs(1, 0, adj);
        for (int i = 1; i <= N; i++) {
            fenwickTree.update(orderingTree.start[i], salaries[i]);
            fenwickTree.update(orderingTree.start[i] + 1, -salaries[i]);
        }
    }

    void solve() throws Exception {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < M; i++) {
            StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            char flag = stringTokenizer.nextToken().charAt(0);
            if (flag == 'p') {
                int a = Integer.parseInt(stringTokenizer.nextToken());
                int x = Integer.parseInt(stringTokenizer.nextToken());
                fenwickTree.update(orderingTree.start[a] + 1, x);
                fenwickTree.update(orderingTree.end[a] + 1, -x);
            } else {
                int a = Integer.parseInt(stringTokenizer.nextToken());
                result.append(fenwickTree.getVal(orderingTree.start[a])).append('\n');
            }
        }
        bufferedWriter.write(result.toString());
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
