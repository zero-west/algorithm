import java.io.*;
import java.util.*;

public class Main {
    int N;
    int zeros;
    int[] arr;
    Map<Integer, Integer> mapping = new HashMap<>();

    void init() throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bufferedReader.readLine());
        arr = Arrays.stream(bufferedReader.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        bufferedReader.close();

        for (int i = 0; i < N - 1; i++) {
            if (arr[i] == 0) zeros++;
            for (int j = i + 1; j < N; j++) {
                if (Math.abs(arr[i] + arr[j]) > 1000000000) continue;
                mapping.merge(arr[i] + arr[j], 1, Integer::sum);
            }
        }
        zeros += (arr[N - 1] == 0) ? 1 : 0;
    }

    void solve() {
        int result = 0;
        for (int k : arr) {
            if (!mapping.containsKey(k)) continue;
            int flag = mapping.get(k) - zeros + ((k == 0) ? 1 : 0);
            if (flag > 0) result++;
        }
        System.out.println(result);
    }

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.init();
        main.solve();
    }
}
