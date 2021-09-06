class Solution {
    
    private val ret: MutableList<List<Int>> = mutableListOf()
    private val visited: BooleanArray = BooleanArray(20) { false }

    private fun dfs(n: Int, k: Int, cur: Int, count: Int) {
        if (count == k) {
            val curList = mutableListOf<Int>()
            for (i in 0 until n) {
                if (visited[i]) {
                    curList.add(i + 1)
                }
            }
            ret.add(curList)
            return
        }

        if (cur == n) return

        visited[cur] = true
        dfs(n, k, cur + 1, count + 1)
        visited[cur] = false
        dfs(n, k, cur + 1, count)
    }

    fun combine(n: Int, k: Int): List<List<Int>> {
        dfs(n, k, 0, 0)

        return ret
    }
}
