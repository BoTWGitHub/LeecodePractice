from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        
        cur = head
        next_node = head
        while cur:
            while next_node and next_node.val == cur.val:
                next_node = next_node.next
            cur.next = next_node
            cur = cur.next
        
        return head
        
solution = Solution()
head = ListNode(1, ListNode(1, ListNode(2, ListNode(3, ListNode(3)))))
head = solution.deleteDuplicates(head)
while head:
    print(head.val)
    head = head.next