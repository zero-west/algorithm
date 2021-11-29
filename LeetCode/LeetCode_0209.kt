import kotlin.math.min

class Solution {
    fun minSubArrayLen(target: Int, nums: IntArray): Int {
        var answer = Int.MAX_VALUE

        var curSum = 0
        var p = 0
        var q = 0
        while (q < nums.size) {
            while (q < nums.size) {
                curSum += nums[q++]
                if (curSum >= target) {
                    answer = min(answer, q - p)
                    break
                }
            }

            while (p < q) {
                curSum -= nums[p++]
                if (curSum >= target) {
                    answer = min(answer, q - p)
                } else {
                    break
                }
            }
        }
        return if (answer == Int.MAX_VALUE) 0 else answer
    }
}
