'''
Given the head of a linked list, remove the nth node from the end of the list and return its head.
'''
from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head.next:
            return None
        fast = head
        for _ in range(n):
            fast = fast.next
        if not fast:
            return head.next
        slow = head
        while fast.next:
            slow = slow.next
            fast = fast.next
        
        slow.next = slow.next.next
        return head

    def removeNthFromEnd2(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        def depth(node: ListNode) -> int:
            if not node:
                return 0
            x = depth(node.next)
            if x==n:
                node.next = node.next.next
            
            return x+1
        
        x = depth(head)
        if x==n:
            return head.next
        return head

    def removeNthFromEnd3(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head or not head.next:
            return None
        cur = head
        temp = []
        while cur:
            temp.append(cur)
            if len(temp)>n+1:
                temp.pop(0)
            cur = cur.next
        if len(temp)==n:
            head = temp[1]
        elif len(temp)>1:
            temp[0].next = temp[1].next
        else:
            temp[0].next = None
        
        return head

solution = Solution()
head = ListNode(1, ListNode(2))
n = 2
head = solution.removeNthFromEnd3(head, n)
while head:
    print(head.val)
    head = head.next