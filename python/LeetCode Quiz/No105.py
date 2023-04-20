'''
Given two integer arrays preorder and inorder
 where preorder is the preorder traversal of a binary tree
 and inorder is the inorder traversal of the same tree
, construct and return the binary tree.
'''
from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        self._map = {val:i for i, val in enumerate(inorder)}
        def builder(left: int, right: int) -> TreeNode:
            if left>right:
                return None
            root = TreeNode(preorder.pop(0))
            sep = self._map[root.val]
            root.left = builder(left, sep-1)
            root.right = builder(sep+1, right)

            return root
        
        return builder(0, len(inorder)-1)

def inorderPrintTree(node: TreeNode):
    if not node:
        return
    inorderPrintTree(node.left)
    print(node.val, end=',')
    inorderPrintTree(node.right)

def main():
    solution = Solution()

    preorder = [3,9,20,15,7]
    inorder = [9,3,15,20,7]
    
    node = solution.buildTree(preorder, inorder)
    inorderPrintTree(node)

if __name__=='__main__':
    main()