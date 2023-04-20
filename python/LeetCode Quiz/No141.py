'''
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
'''

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x, next=None):
        self.val = x
        self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head:
            return False
        h1 = head.next
        h2 = head
        while h1:
            if h1.next == h2 or h1.next == h1:
                return True
            h2 = h2.next
            if h2 == h1:
                h1 = h1.next
                h2 = head
        
        return False
    
    def hasCycle2(self, head: Optional[ListNode]) -> bool:
        fast = head
        slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                return True

        return False

solution = Solution()
head = ListNode(-1, ListNode(-7, ListNode(7, ListNode(-4, ListNode(19, ListNode(6, ListNode(-9, ListNode(-5, ListNode(-2, ListNode(-5))))))))))
cur = head
while cur.next:
    cur = cur.next
cur.next = cur

print(solution.hasCycle2(head))
