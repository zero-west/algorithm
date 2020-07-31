import java.util.ArrayList;
import java.util.HashSet;
import java.util.regex.Pattern;
import java.util.stream.Collectors;
import java.util.stream.Stream;

class Solution {
    ArrayList<ArrayList<String>> matchedList = new ArrayList<>();

    ArrayList<String> selectList = new ArrayList<>();
    HashSet<HashSet<String>> selectSet = new HashSet<>();

    public int solution(String[] user_id, String[] banned_id) {
        Stream.of(banned_id).forEach(cur -> {
            Pattern pattern = Pattern.compile("^" + cur.replace('*', '.') + "$");
            ArrayList<String> curList = Stream.of(user_id)
                    .filter(str -> pattern.matcher(str).find()).collect(Collectors.toCollection(ArrayList::new));
            matchedList.add(curList);
        });
        solve(0);
        return selectSet.size();
    }

    public void solve(int idx) {
        if (idx == matchedList.size()) {
            HashSet<String> curSet = new HashSet<>(selectList);
            if (curSet.size() == selectList.size()) {
                selectSet.add(curSet);
            }
            return;
        }

        ArrayList<String> curMatchedList = matchedList.get(idx);
        for (String cur : curMatchedList) {
            selectList.add(cur);
            solve(idx + 1);
            selectList.remove(selectList.size() - 1);
        }
    }
}
