import sys
from collections import Counter

sys.setrecursionlimit(10 ** 8)


class Node:
    def __init__(self, key):
        self.key = key
        self.mapping = {}
        self.child = {}


class Trie:
    def __init__(self):
        self.head = Node(None)

    def insert(self, inserted):
        cur_node = self.head
        total_len = len(inserted)

        for idx, ch in enumerate(inserted):
            if total_len - idx in cur_node.mapping:
                cur_node.mapping[total_len - idx] += 1
            else:
                cur_node.mapping[total_len - idx] = 1

            if ch not in cur_node.child:
                cur_node.child[ch] = Node(ch)
            cur_node = cur_node.child[ch]

    def find(self, f_word):
        cur_node = self.head
        q_mark = Counter(f_word)['?']

        for ch in f_word:
            if ch == '?':
                return cur_node.mapping[q_mark] if q_mark in cur_node.mapping else 0
            if ch not in cur_node.child:
                return 0
            cur_node = cur_node.child[ch]
        return 0


def solution(words, queries):
    answer = [None] * len(queries)
    prefix_trie = Trie()
    suffix_trie = Trie()

    for word in words:
        prefix_trie.insert(word)
        suffix_trie.insert(word[::-1])

    for idx, query in enumerate(queries):
        if query[0] == '?':
            answer[idx] = suffix_trie.find(query[::-1])
        else:
            answer[idx] = prefix_trie.find(query)

    return answer