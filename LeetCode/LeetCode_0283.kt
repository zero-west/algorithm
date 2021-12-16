class Solution {
    fun swap(arr: IntArray, p: Int, q: Int) {
        val tmp = arr[p]
        arr[p] = arr[q]
        arr[q] = tmp
    }

    fun moveZeroes(nums: IntArray): Unit {
        var nonZeroCount = 0
        for (i in 0..nums.lastIndex) {
            if (nums[i] != 0) {
                swap(nums, nonZeroCount++, i)
            }
        }
    }
}
