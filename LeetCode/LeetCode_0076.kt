class Solution {
    fun minWindow(s: String, t: String): String {
        var need = t.length
        val needCount = HashMap<Char, Int>()
        t.forEach { ch ->
            needCount.merge(ch, 1, Integer::sum)
        }

        var ans = ""
        var left = 0
        val curCount = HashMap<Char, Int>()
        
        for ((idx, ch) in s.withIndex()) {
            if (ch in needCount) {
                curCount.merge(ch, 1, Integer::sum)
                if (curCount.getValue(ch) <= needCount.getValue(ch)) {
                    need--
                }
            }

            if (need == 0) {
                while (left <= s.lastIndex) {
                    if (s[left] in curCount) {
                        if (curCount.getValue(s[left]) == needCount.getValue(s[left])) {
                            break
                        }
                        curCount.merge(s[left], -1, Integer::sum)
                    }
                    left++
                }

                if (ans.isEmpty() || idx + 1 - left < ans.length) {
                    ans = s.substring(left, idx + 1)
                    curCount.merge(s[left++], -1, Integer::sum)
                    need++
                }
            }
        }

        return ans
    }
}
