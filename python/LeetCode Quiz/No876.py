from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        count = 0
        while cur:
            count+=1
            cur = cur.next

        mid = count//2
        cur = head
        
        while mid>0:
            mid-=1
            cur=cur.next
        
        return cur

solution = Solution()
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
print(solution.middleNode(head).val)