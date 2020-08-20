# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    # Iterative
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        start_node = ListNode()
        cur_node = start_node

        while l1 and l2:
            if l1.val < l2.val:
                cur_node.next = l1
                l1 = l1.next
            else:
                cur_node.next = l2
                l2 = l2.next
            cur_node = cur_node.next

        if l1:
            cur_node.next = l1
        if l2:
            cur_node.next = l2
        return start_node.next

    # Recursive
    def mergeTwoLists2(self, l1: ListNode, l2: ListNode) -> ListNode:
        if (not l1) or (l2 and l1.val > l2.val):
            l1, l2 = l2, l1
        if l1:
            l1.next = self.mergeTwoLists2(l1.next, l2)
        return l1
