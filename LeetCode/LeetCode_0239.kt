import java.util.*

class Solution {
    fun maxSlidingWindow(nums: IntArray, k: Int): IntArray {
        val treeMap = TreeMap<Int, Int>()

        for (i in 0 until k - 1) {
            treeMap.merge(nums[i], 1, Integer::sum)
        }

        val ans = mutableListOf<Int>()
        for (i in 0..(nums.size - k)) {
            treeMap.merge(nums[i + k - 1], 1, Integer::sum)
            ans.add(treeMap.lastKey())

            val left = treeMap[nums[i]]
            if (left == 1) {
                treeMap.remove(nums[i])
            } else {
                treeMap[nums[i]] = left!! - 1
            }
        }

        return ans.toIntArray()
    }
}
