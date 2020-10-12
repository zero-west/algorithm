import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(stringTokenizer.nextToken());
        int M = Integer.parseInt(stringTokenizer.nextToken());

        int[] heights = new int[N];
        int[] weights = new int[N+1];

        stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        int idx = 0;
        while (stringTokenizer.hasMoreTokens()) {
            heights[idx] = Integer.parseInt(stringTokenizer.nextToken());
            idx++;
        }

        while (M != 0) {
            M--;
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
            int a = Integer.parseInt(stringTokenizer.nextToken());
            int b = Integer.parseInt(stringTokenizer.nextToken());
            int c = Integer.parseInt(stringTokenizer.nextToken());
            weights[a-1] += c;
            weights[b] -= c;
        }

        int weightSum = 0;
        for (int i = 0; i < N; i++) {
            weightSum += weights[i];
            bufferedWriter.write(heights[i] + weightSum + " ");
        }
        bufferedWriter.flush();
    }
}

