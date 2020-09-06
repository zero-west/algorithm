import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        int N = Integer.parseInt(br.readLine());
        long[] arr1 = Arrays.stream(("0 " + br.readLine()).split(" "))
                .mapToLong(Long::parseLong).toArray();
        Arrays.parallelPrefix(arr1, (x, y) -> x + y);

        int M = Integer.parseInt(br.readLine());
        long[] arr2 = Arrays.stream(("0 " + br.readLine()).split(" "))
                .mapToLong(Long::parseLong).toArray();
        Arrays.parallelPrefix(arr2, (x, y) -> x + y);

        Map<Long, Long> mapping = new HashMap<>();
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                mapping.merge(arr1[i] - arr1[j], 1L, Long::sum);
            }
        }

        long result = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = 0; j < i; j++) {
                result += mapping.getOrDefault(T - arr2[i] + arr2[j], 0L);
            }
        }
        System.out.println(result);
    }
}
