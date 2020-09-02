import sys

sys.setrecursionlimit(10 ** 8)


class Node:
    def __init__(self, a, b):
        self.x = a
        self.y = b
        self.left = None
        self.right = None


class Tree:
    def __init__(self, a, b):
        self.head = Node(a, b)

    def insert(self, a, b, prev_depth):
        cur_node = self.head
        while cur_node.y != prev_depth:
            if a < cur_node.x:
                cur_node = cur_node.left
            else:
                cur_node = cur_node.right

        if a < cur_node.x:
            cur_node.left = Node(a, b)
        else:
            cur_node.right = Node(a, b)


def solution(nodeinfo):
    mapping = {tuple(node): idx + 1 for idx, node in enumerate(nodeinfo)}

    levels = {}
    for cur_node in nodeinfo:
        x, y = cur_node
        if y in levels:
            levels[y].append(x)
        else:
            levels[y] = [x]
    levels = sorted(levels.items(), key=lambda k: k[0], reverse=True)

    tree = Tree(levels[0][1][0], levels[0][0])
    for idx in range(1, len(levels)):
        y, xList = levels[idx]
        for x in xList:
            tree.insert(x, y, levels[idx - 1][0])

    answer = [[], []]

    def pre_dfs(cur_node):
        answer[0].append(mapping[(cur_node.x, cur_node.y)])
        if cur_node.left:
            pre_dfs(cur_node.left)
        if cur_node.right:
            pre_dfs(cur_node.right)

    def post_dfs(cur_node):
        if cur_node.left:
            post_dfs(cur_node.left)
        if cur_node.right:
            post_dfs(cur_node.right)
        answer[1].append(mapping[(cur_node.x, cur_node.y)])

    pre_dfs(tree.head)
    post_dfs(tree.head)
    return answer
