import sys

sys.setrecursionlimit(10 ** 7)

N = int(sys.stdin.readline())


class Node:
    def __init__(self, key):
        self.key = key
        self.child = []
        self.visited = 1
        self.isEnd = -1


class Trie:
    def __init__(self):
        self.head = Node(None)

    def insert(self, insert_word, idx):
        cur_node = self.head
        cur_cnt = 0
        cur_total = idx
        
        for ch in insert_word:
            if cur_total != 0:
                inFlag = False
                for cur_tuple in cur_node.child:
                    if cur_tuple[0] == ch:
                        cur_cnt += cur_total
                        cur_total = cur_tuple[1].visited
                        cur_tuple[1].visited += 1
                        cur_node = cur_tuple[1]
                        inFlag = True
                        break
                if not inFlag:
                    cur_cnt += cur_total
                    cur_node.child.append((ch, Node(ch)))
                    cur_total = 0
                    cur_node = cur_node.child[-1][1]
            else:
                cur_node.child.append((ch, Node(ch)))
                cur_node = cur_node.child[-1][1]

        cur_node.isEnd = cur_cnt + cur_total

    def search(self, search_word):
        global N

        cur_node = self.head
        res = 0
        cur_total = N

        for ch in search_word:
            flag = False
            for cur_tuple in cur_node.child:
                if cur_tuple[0] == ch:
                    res += cur_total
                    cur_total = cur_tuple[1].visited
                    flag = True
                    cur_node = cur_tuple[1]
                    break

            if not flag:
                return res + cur_total, -1

        if cur_node.isEnd != -1:
            return res, cur_node.isEnd
        else:
            return res + cur_total, -1


trie = Trie()
for i in range(N):
    trie.insert(sys.stdin.readline().rstrip(), i)

Q = int(sys.stdin.readline())
for _ in range(Q):
    searchWord = sys.stdin.readline().rstrip()
    info = trie.search(searchWord)
    print(info[0]) if info[1] == -1 else print(info[1] + len(searchWord) + 1)
