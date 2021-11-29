import kotlin.math.max

class Solution {
    fun findLength(nums1: IntArray, nums2: IntArray): Int {
        var answer = 0

        val dp = Array(nums1.size + 1) { IntArray(nums2.size + 1) { 0 } }
        for (i in 1..nums1.size) {
            for (j in 1..nums2.size) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1
                    answer = max(answer, dp[i][j])
                } else {
                    dp[i][j] = 0
                }
            }
        }
        return answer
    }
}
