import java.util.*;
import java.util.stream.Stream;

class Solution {
    final Map<Integer, Integer> counts = new LinkedHashMap<>();

    public int[] solution(String s) {
        Stream.of(s.replaceAll("[}{]", "").split(",")).mapToInt(Integer::parseInt)
                .forEach(i -> counts.merge(i, 1, Integer::sum));
        return counts.entrySet().stream().sorted(Collections.reverseOrder(Map.Entry.comparingByValue()))
                .map(Map.Entry::getKey).mapToInt(x -> x).toArray();
    }
}
