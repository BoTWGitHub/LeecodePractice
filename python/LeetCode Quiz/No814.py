'''
Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def trim(node: Optional[TreeNode]) -> bool:
            if not node:
                return False
            if node.val==0:
                if not trim(node.left):
                    node.left = None
                if not trim(node.right):
                    node.right = None
                if not node.left and not node.right:
                    return False
                else:
                    return True
            else:
                if not trim(node.left):
                    node.left = None
                if not trim(node.right):
                    node.right = None
                return True
        trim(root)
        if not root.left and not root.right and root.val==0:
            return None
        return root

def printTree(root: TreeNode):
    if not root:
        print('n', end='-')
        return
    print(root.val, end='-')
    printTree(root.left)
    printTree(root.right)

def main():
    solution = Solution()

    root = TreeNode(1, TreeNode(0, TreeNode(0), TreeNode(0)), TreeNode(1, TreeNode(0), TreeNode(1)))
    printTree(root)
    print('')

    root = solution.pruneTree(root)
    printTree(root)
    print('')

if __name__=='__main__':
    main()
