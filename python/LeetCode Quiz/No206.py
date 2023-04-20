from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        rev = None
        while head:
            rev, rev.next, head = head, rev, head.next
        
        return rev

def printList(head: ListNode):
    cur = head
    while cur:
        print(f'{cur.val}->', end='')
        cur = cur.next
    print('')

solution = Solution()
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
printList(head)
head = solution.reverseList(head)
printList(head)