class Solution {
    int[] priority = new int[26];

    public int solution(String skill, String[] skill_trees) {
        int answer = 0;

        for (int i = 0; i < skill.length(); i++) {
            priority[skill.charAt(i) - 'A'] = i + 1;
        }

        for (String tree : skill_trees) {
            int check = 0;
            boolean flag = true;
            for (int i = 0; i < tree.length(); i++) {
                int curPriority = priority[tree.charAt(i) - 'A'];
                if (curPriority == 0) continue;
                if (curPriority != ++check) {
                    flag = false;
                    break;
                }
            }
            if (flag) answer++;
        }
        return answer;
    }
}
