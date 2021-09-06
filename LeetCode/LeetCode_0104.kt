class Solution {
    fun maxDepth(root: TreeNode?): Int {
        if (root == null) return 0

        val que = ArrayDeque<TreeNode>()
        que.add(root)

        var depth = 0
        while (!que.isEmpty()) {
            depth += 1

            var curSize = que.size
            while (curSize != 0) {
                val curRoot = que.removeFirst()
                if (curRoot.left != null) {
                    que.add(curRoot.left!!)
                }
                if (curRoot.right != null) {
                    que.add(curRoot.right!!)
                }
                curSize--
            }
        }
        return depth
    }
}
