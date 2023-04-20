from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if not head:
            return head

        while head.val == val:
            head = head.next
            
        cur = head.next
        last = head
        while cur:
            if cur.val == val:
                last.next = cur.next
                cur = cur.next
            else:
                last = cur
                cur = cur.next

        return head

solution = Solution()
data = ListNode(1, ListNode(2, ListNode(6, ListNode(3, ListNode(4, ListNode(5, ListNode(6)))))))
data = solution.removeElements(data, 6)
while data:
    print(data.val)
    data = data.next