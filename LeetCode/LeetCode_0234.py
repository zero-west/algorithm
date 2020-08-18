from collections import deque


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True

        cur_node = head
        dq = deque([cur_node.val])
        while cur_node.next is not None:
            cur_node = cur_node.next
            dq.append(cur_node.val)

        while len(dq) > 1:
            if dq.popleft() != dq.pop():
                return False
        return True
