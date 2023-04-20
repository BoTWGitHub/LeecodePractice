'''
Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. 
For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

We want to do the transformation in place. 
After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. 
You should return the pointer to the smallest element of the linked list.
'''
from typing import Optional

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def printTree(self, node):
        if not node:
            return
        node.printTree(node.left)
        print(node.val, end=' -> ')
        node.printTree(node.right)

    def printList(self, node):
        head = node
        cur = head
        while cur:
            print(cur.val, end=' -> ')
            cur = cur.right
            if cur == head:
                break
        print('')

    def printRevList(self, node):
        head = node
        cur = head
        while cur:
            print(cur.val, end=' -> ')
            cur = cur.left
            if cur == head:
                break
        print('')

class Solution:
    def treeToDoublyList(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return root
        self.__head = None
        self.__last = None
        def traverser(node):
            if not node:
                return
            traverser(node.left)
            if not self.__last:
                self.__head = node
            else:
                node.left = self.__last
                self.__last.right = node
            self.__last = node
            traverser(node.right)
        traverser(root)
        self.__head.left = self.__last
        self.__last.right = self.__head
        return self.__head

def main():
    solution = Solution()

    root = Node(4, Node(2, Node(1), Node(3)), Node(5))
    root.printTree(root)
    print('')
    head = solution.treeToDoublyList(root)
    head.printList(head)
    head.printRevList(head)

if __name__=='__main__':
    main()
