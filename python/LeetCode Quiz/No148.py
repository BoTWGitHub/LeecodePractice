'''
Given the head of a linked list, return the list after sorting it in ascending order.
'''

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        count = 0
        cur = head
        while cur:
            count+=1
            cur = cur.next
        if count == 2:
            if head.val > head.next.val:
                temp = head.next
                head.next.next = head
                head.next = None
                return temp
            return head
        
        half = count//2-1
        cur = head
        while half:
            half-=1
            cur = cur.next
        p1 = head
        p2 = cur.next
        cur.next = None

        p1 = self.sortList(p1)
        p2 = self.sortList(p2)

        if p1.val<=p2.val:
            head = p1
        else:
            head = p2

        while p1 and p2:
            if p1.val<=p2.val:
                if p1.next:
                    if p1.next.val>p2.val:
                        temp = p1.next
                        p1.next = p2
                        p1 = temp
                    else:
                        p1=p1.next
                else:
                    p1.next = p2
                    p1 = None
            else:
                if p2.next:
                    if p2.next.val>=p1.val:
                        temp = p2.next
                        p2.next = p1
                        p2 = temp
                    else:
                        p2=p2.next
                else:
                    p2.next = p1
                    p2 = None

        return head

solution = Solution()
#head = ListNode(4, ListNode(2, ListNode(1, ListNode(3))))
head = ListNode(1, ListNode(1, ListNode(3, ListNode(3, ListNode(1)))))
head = solution.sortList(head)
while head:
    print(head.val)
    head = head.next