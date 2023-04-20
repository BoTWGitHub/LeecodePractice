'''
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
'''
from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return root
        
        q = [root]
        while q:
            size = len(q)
            for i in range(size-1):
                q[i].next = q[i+1]

            for _ in range(size):
                node = q.pop(0)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return root

def printTreeNext(root: Node):
    if not root:
        return
    printTreeNext(root.left)
    printTreeNext(root.right)
    if root.next:
        print(f'{root.val} -> {root.next.val}')
    else:
        print(f'{root.val} -> None')

def main():
    solution = Solution()

    root = Node(1, Node(2, Node(4), Node(5)), Node(3, None, Node(7)))
    printTreeNext(root)

    print('-----------------------------------------')

    root = solution.connect(root)
    printTreeNext(root)

if __name__=='__main__':
    main()