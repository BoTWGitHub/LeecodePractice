'''
Given the head of a singly linked list
, return true if it is a palindrome.
'''
from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val: int=0, next: "ListNode"=None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        stack = []
        cur = head
        while cur:
            stack.append(cur.val)
            cur = cur.next
        cur = head
        while cur:
            if cur.val!=stack.pop():
                return False
            cur = cur.next
        return True
    
    def isPalindrome2(self, head: Optional[ListNode]) -> bool: #still O(n) of time but O(1) of space
        if not head:
            return False
        res = True
        #seperate list in half
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        second = slow.next
        #reverse second list
        second = self._reverseList(second)
        last = second

        #compare two list
        cur = head
        while second:
            if second.val != cur.val:
                res = False
                break
            second = second.next
            cur = cur.next

        #recover the original list?
        second = self._reverseList(last)
        slow.next = second

        return res
    
    def _reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        rev = None
        while head:
            rev, rev.next, head = head, rev, head.next

        return rev

def printList(head: "ListNode"):
    cur = head
    while cur:
        print(f'{cur.val}->', end='')
        cur = cur.next
    print('')

def main():
    head = ListNode(1, ListNode(2, ListNode(2, ListNode(1, ListNode(3)))))
    printList(head)
    print(Solution.isPalindrome2(Solution(), head))
    printList(head)

if __name__=='__main__':
    main()