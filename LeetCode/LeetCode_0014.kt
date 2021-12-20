import kotlin.math.min

class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        val firstStr = strs[0]
        var prefixLength = strs[0].length

        for (i in 1..strs.lastIndex) {
            val curStr = strs[i]
            var count = 0
            for (j in 0 until min(curStr.length, prefixLength)) {
                if (curStr[j] == firstStr[j]) count++
                else break
            }
            prefixLength = min(prefixLength, count)
        }

        return firstStr.substring(0, prefixLength)
    }
}

