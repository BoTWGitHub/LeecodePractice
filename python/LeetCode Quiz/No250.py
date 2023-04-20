'''
Given the root of a binary tree, return the number of uni-value subtrees.

A uni-value subtree means all nodes of the subtree have the same value.
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countUnivalSubtrees(self, root: Optional[TreeNode]) -> int:
        self._res = 0
        def uniSubTree(node: Optional[TreeNode]) -> bool:
            if not node:
                return True
            if not node.left and not node.right:
                self._res+=1
                return True

            left = uniSubTree(node.left)
            if node.left:
                left = left and node.val == node.left.val

            right = uniSubTree(node.right)
            if node.right:
                right = right and node.val == node.right.val

            if left and right:
                self._res+=1
            return left and right
            
        uniSubTree(root)
        return self._res
        

def main():
    solution = Solution()
    
    root = TreeNode(5, TreeNode(1, TreeNode(5), TreeNode(5)), TreeNode(5, None, TreeNode(5)))
    print(solution.countUnivalSubtrees(root))

if __name__=='__main__':
    main()
