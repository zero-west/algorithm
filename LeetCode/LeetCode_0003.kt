import java.lang.Integer.max

class Solution {
    fun lengthOfLongestSubstring(s: String): Int {
        var ans = 0

        val set = mutableSetOf<Char>()
        var left = 0
        for ((right, ch) in s.withIndex()) {
            if (ch in set) {
                do {
                    set.remove(s[left])
                } while (s[left++] != ch)
            } else {
                ans = max(ans, right - left + 1)
            }
            set.add(ch)
        }
        return ans
    }
}
