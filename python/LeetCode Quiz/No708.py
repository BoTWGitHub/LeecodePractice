'''
Given a Circular Linked List node
, which is sorted in ascending order
, write a function to insert a value insertVal into the list such that it remains a sorted circular list. 
The given node can be a reference to any single node in the list and may not necessarily be the smallest value in the circular list.

If there are multiple suitable places for insertion
, you may choose any place to insert the new value. 
After the insertion, the circular list should remain sorted.

If the list is empty (i.e., the given node is null)
, you should create a new single circular list and return the reference to that single node. 
Otherwise, you should return the originally given node.
'''
from queue import Empty
from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next

class Solution:
    def insert(self, head: 'Optional[Node]', insertVal: int) -> 'Node':
        if not head:
            head = Node(insertVal)
            head.next = head
            return head

        origin_head = head
        #cut the circle from the smallest val
        cur = head
        while cur:
            if cur.next.val < cur.val:
                head = cur.next
                cur.next = None
            elif cur.next == head:
                cur.next = None
            cur = cur.next
        
        #insert the val
        cur = head
        if insertVal<cur.val:
            head = Node(insertVal, head)
        else:
            while cur.next:
                if cur.next.val>insertVal:
                    temp = cur.next
                    cur.next = Node(insertVal, temp)
                    break
                cur = cur.next
            if not cur.next:
                cur.next = Node(insertVal)
        
        #circle the list back
        cur = head
        while cur.next:
            cur = cur.next
        cur.next = head

        return origin_head
    def insert2(self, head: 'Optional[Node]', insertVal: int) -> 'Node':
        if not head:
            head = Node(insertVal)
            head.next = head
            return head
        
        cur = head
        next = head.next
        if cur == next:
            cur.next = Node(insertVal, cur)
            return head
        while True:
            if cur.val<=insertVal:
                if next.val>insertVal or next.val<cur.val:
                    cur.next = Node(insertVal, next)
                    return head
            else:
                if next.val<cur.val and next.val>insertVal or next==head:
                    cur.next = Node(insertVal, next)
                    return head
            cur = cur.next
            next = cur.next
        
def printCircularList(head: Optional[Node]):
    if not head:
        print('empty')
        return
    cur = head
    while cur:
        print(f'{cur.val}->', end='')
        cur = cur.next
        if cur==head:
            break
    print('v')
    

def main():
    head = Node(3, Node(5, Node(1)))
    cur = head
    while cur.next:
        cur = cur.next
    cur.next = head
    insertVal = 5
    printCircularList(head)

    head = Solution.insert2(Solution(), head, insertVal)
    printCircularList(head)


if __name__=='__main__':
    main()