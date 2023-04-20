'''
Given the head of a linked list
, rotate the list to the right by k places.
'''
from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        length = 0
        cur = head
        while cur:
            length+=1
            cur = cur.next
        
        k%=length
        fast = head
        while k>0:
            k-=1
            fast = fast.next
        cur = head
        while fast.next:
            cur = cur.next
            fast = fast.next
        fast.next = head
        head = cur.next
        cur.next = None
        return head

def printList(head: ListNode):
    cur = head
    while cur:
        print(f'{cur.val}->', end='')
        cur = cur.next
    print('')

def main():
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    k = 2
    printList(head)

    head = Solution.rotateRight(Solution(), head, k)
    printList(head)


if __name__=='__main__':
    main()
