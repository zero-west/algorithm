import java.util.*

class Solution {
    fun topKFrequent(nums: IntArray, k: Int): IntArray {
        val count = mutableMapOf<Int, Int>()
        for (num in nums) {
            count.merge(num, 1, Integer::sum)
        }

        val treeSet = TreeSet<Map.Entry<Int, Int>>(compareBy({ -it.value }, { it.key }))
        treeSet.addAll(count.entries)

        return treeSet.take(k).map { it.key }.toIntArray()
    }
}
