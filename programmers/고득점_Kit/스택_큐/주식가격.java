import java.util.Stack;

class Solution {

    static class Pair {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];

        var stack = new Stack<Pair>();
        for (int i = 0; i < prices.length; i++) {
            var p = prices[i];

            while (!stack.empty() && stack.peek().first > p) {
                var pair = stack.pop();
                answer[pair.second] = i - pair.second;
            }

            stack.add(new Pair(p, i));
        }

        while (!stack.empty()) {
            var pair = stack.pop();
            answer[pair.second] = prices.length - 1 - pair.second;
        }

        return answer;
    }
}
