import java.util.ArrayList;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        if (progresses.length == 0) return new int[]{};
        else if (progresses.length == 1) return new int[]{1};

        var answer = new ArrayList<Integer>() {{
            add(1);
        }};
        var timeSum = Math.ceil((double) (100 - progresses[0]) / speeds[0]);

        for (int i = 1; i < progresses.length; i++) {
            var curProgress = progresses[i];
            var curTime = Math.ceil((double) (100 - curProgress) / speeds[i]);

            if (timeSum >= curTime) {
                var lastIndex = answer.size() - 1;
                answer.set(lastIndex, answer.get(lastIndex) + 1);
            } else {
                answer.add(1);
                timeSum = curTime;
            }
        }

        return answer.stream().mapToInt(i -> i).toArray();
    }
}
