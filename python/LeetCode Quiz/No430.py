'''
You are given a doubly linked list
, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer.
This child pointer may or may not point to a separate doubly linked list
, also containing these special nodes. 
These child lists may have one or more children of their own, and so on
, to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list
, flatten the list so that all the nodes appear in a single-level, doubly linked list. 
Let curr be a node with a child list. 
The nodes in the child list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. 
The nodes in the list must have all of their child pointers set to null.
'''
from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, val: int, prev: 'Node'=None, next: 'Node'=None, child: 'Node'=None):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return head
        def flatList(head: 'Node', next: 'Optional[Node]') -> 'Node':
            cur = head
            last = head
            while cur:
                jump = None
                if cur.child:
                    jump = cur.next
                    cur.next = flatList(cur.child, cur.next)
                    cur.child = None
                last = cur
                if jump:
                    cur = jump
                else:
                    cur = cur.next
            last.next = next
            return head
        flatList(head, None)
        cur = head.next
        last = head
        while cur:
            cur.prev = last
            last = cur
            cur = cur.next
        return head

def printNode(head: Node):
    cur = head
    while cur:
        print(f'{cur.val}->', end='')
        if cur.child:
            print('v')
            printNode(cur.child)
        cur = cur.next
    print('^')

def main():
    '''head = Node(1, None, Node(2, None, Node(3, None, Node(4, None, Node(5, None, Node(6))))))
    cur = head
    while cur:
        last = cur
        cur = cur.next
        if cur:
            cur.prev = last
    
    cur = head.next.next
    cur.child = Node(7, None, Node(8, None, Node(9, None, Node(10))))
    cur = cur.child
    while cur:
        last = cur
        cur = cur.next
        if cur:
            cur.prev = last
    
    cur = head.next.next.child.next
    cur.child = Node(11, None, Node(12))
    cur = cur.child
    while cur:
        last = cur
        cur = cur.next
        if cur:
            cur.prev = last'''

    head = Node(1)
    head.child = Node(2)
    head.child.child = Node(3)
    
    printNode(head)
    print('-----------------------')
    Solution.flatten(Solution(), head)
    printNode(head)

if __name__=='__main__':
    main()
