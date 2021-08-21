class Solution {
    fun search(nums: IntArray, target: Int): Int {
        val pivot = nums.withIndex().minByOrNull { (_, f) -> f }?.index
            ?: return -1

        var s = 0
        var e = nums.lastIndex

        while (s <= e) {
            val mid = s + (e - s) / 2
            val midPivot = (mid + pivot) % nums.size

            if (nums[midPivot] > target) {
                e = mid - 1
            } else if (nums[midPivot] < target) {
                s = mid + 1
            } else {
                return midPivot
            }
        }

        return -1
    }
}
