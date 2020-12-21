import java.util.*;
import java.util.function.Predicate;

class Solution {
    int res;
    String[] friends = new String[]{"A", "C", "F", "J", "M", "N", "R", "T"};
    Predicate<List<String>>[] info;
    List<String> select = new ArrayList<>();
    boolean[] visited = new boolean[8];

    private void solve(int idx) {
        if (idx == 8) {
            boolean flag = true;
            for (var p : info) {
                flag &= p.test(select);
                if (!flag) break;
            }
            if (flag) res++;
            return;
        }

        for (int i = 0; i < 8; i++) {
            if (!visited[i]) {
                visited[i] = true;
                select.add(friends[i]);
                solve(idx + 1);
                select.remove(select.size() - 1);
                visited[i] = false;
            }
        }
    }

    public int solution(int n, String[] data) {
        info = new Predicate[data.length];
        for (int i = 0; i < data.length; i++) {
            String[] condition = data[i].split("[~=<>]");
            char flag = data[i].charAt(3);
            info[i] = strings -> {
                int p = 0, q = 0;
                for (int j = 0; j < strings.size(); j++) {
                    if (strings.get(j).equals(condition[0])) p = j;
                    if (strings.get(j).equals(condition[1])) q = j;
                }
                switch (flag) {
                    case '>':
                        return Math.abs(q - p) - 1 > Integer.parseInt(condition[2]);
                    case '<':
                        return Math.abs(q - p) - 1 < Integer.parseInt(condition[2]);
                    case '=':
                        return Math.abs(q - p) - 1 == Integer.parseInt(condition[2]);
                    default:
                        return false;
                }
            };
        }

        solve(0);
        return res;
    }
}
