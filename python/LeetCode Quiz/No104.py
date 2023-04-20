from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int: #top-down
        if not root:
            return 0

        self._res = 1
        def findDepth(node, level):
            if not node:
                return
            if not node.left and not node.right:
                self._res = max(self._res, level)
                return
            findDepth(node.left, level+1)
            findDepth(node.right, level+1)
        
        findDepth(root, 1)
        return self._res
    
    def maxDepth2(self, root: Optional[TreeNode]) -> int: #bottom-up
        if not root:
            return 0

        def findDepth(node) -> int:
            if not node:
                return 0
            return max(findDepth(node.left)+1, findDepth(node.right)+1)
        
        return findDepth(root)

solution = Solution()
root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
print(solution.maxDepth2(root))