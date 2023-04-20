'''
Given two integer arrays inorder and postorder
 where inorder is the inorder traversal of a binary tree
 and postorder is the postorder traversal of the same tree
, construct and return the binary tree.
'''
from distutils.command.build import build
from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if len(inorder)==0:
            return None
        root = TreeNode(postorder.pop())
        sep = inorder.index(root.val) #this is O(n)
        root.right = self.buildTree(inorder[sep+1:], postorder)
        root.left = self.buildTree(inorder[:sep], postorder)
        return root

    def buildTree2(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        self._map = {val:idx for idx, val in enumerate(inorder)}
        def builder(left: int, right: int) -> TreeNode:
            if left>right:
                return None
            
            root = TreeNode(postorder.pop())
            sep = self._map[root.val]
            root.right = builder(sep+1, right)
            root.left = builder(left, sep-1)
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

    inorder = [9,3,15,20,7]
    postorder = [9,15,7,20,3]
    
    node = solution.buildTree2(inorder, postorder)
    inorderPrintTree(node)

if __name__=='__main__':
    main()
