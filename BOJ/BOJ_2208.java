import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        var NM = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int N = NM[0], M = NM[1];
        int[] pSum = new int[N + 1];

        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(br.readLine());
            pSum[i + 1] = pSum[i] + num;
        }

        int result = 0, tmp = 0;
        for (int i = M; i <= N; i++) {
            tmp = Integer.min(pSum[i - M], tmp);
            result = Integer.max(result, pSum[i] - tmp);
        }
        System.out.println(result);
    }
}