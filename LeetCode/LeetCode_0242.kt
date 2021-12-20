class Solution {
    fun isAnagram(s: String, t: String): Boolean {
        val N = s.length
        if (N != t.length) return false

        val sMap = HashMap<Char, Int>()
        val tMap = HashMap<Char, Int>()

        for (i in 0 until N) {
            sMap.merge(s[i], 1, Int::plus)
            tMap.merge(t[i], 1, Int::plus)
        }
        return sMap == tMap
    }
}

