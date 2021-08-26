import java.lang.Integer.max

class Solution {
    fun characterReplacement(s: String, k: Int): Int {
        var answer = 0
        val count = IntArray(26) { 0 }

        var left = 0
        val len = s.length

        for (right in 0 until len) {
            count[s[right] - 'A']++

            val curMaxIdx: Int = count.withIndex().maxByOrNull { (_, v) -> v }!!.index

            if (right - left + 1 <= k + count[curMaxIdx]) {
                answer = max(answer, right - left + 1)
            } else {
                count[s[left++] - 'A']--
            }
        }

        return answer
    }
}
