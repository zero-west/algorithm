import kotlin.math.max

class Solution {
    fun maxSubArray(nums: IntArray): Int {
        var subRet = nums[0]
        var ret = nums[0]

        for (i in 1..nums.lastIndex) {
            subRet = max(nums[i] + subRet, nums[i])
            if (subRet > ret) {
                ret = subRet
            }
        }
        return ret
    }
}
