class Solution {
    fun intersection(nums1: IntArray, nums2: IntArray): IntArray {
        nums2.sort()

        return nums1.filter {
            val f = nums2.binarySearch(it)
            f >= 0 && nums2[f] == it
        }.toSet().toIntArray()
    }
}
