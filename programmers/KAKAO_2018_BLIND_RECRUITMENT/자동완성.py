import sys

sys.setrecursionlimit(10 ** 8)


class Node:
    def __init__(self, k):
        self.child = {}
        self.key = k
        self.cnt = 1


class Trie:
    def __init__(self):
        self.head = Node(None)

    def insert(self, word):
        cur_node = self.head

        for ch in word:
            if ch not in cur_node.child:
                cur_node.child[ch] = Node(ch)
            else:
                cur_node.child[ch].cnt += 1
            cur_node = cur_node.child[ch]

    def search(self, word):
        cur_node = self.head

        for idx, ch in enumerate(word):
            cur_node = cur_node.child[ch]
            if cur_node.cnt == 1:
                return idx + 1
        return len(word)


def solution(words):
    answer = 0

    trie = Trie()
    for word in words:
        trie.insert(word)
    for word in words:
        answer += trie.search(word)
        print(answer)
    return answer
