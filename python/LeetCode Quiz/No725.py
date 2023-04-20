from typing import Optional
from typing import List

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        l = 0
        node = head
        while node:
            l+=1
            node=node.next
        parts = [l//k] * k
        for i in range(l%k):
            parts[i]+=1
        res = []
        index = 0
        last = head
        while index<k:
            res+=[head]
            while parts[index]>0:
                last = head
                head = head.next
                parts[index]-=1
            if last:
                last.next = None
            index+=1
        return res

head = ListNode(1)
node = head
for i in range(2, 11):
    node.next = ListNode(i)
    node = node.next

solution = Solution()
temp = solution.splitListToParts(head, 3)
for n in temp:
    while n:
        print(n.val)
        n = n.next
    print('/')