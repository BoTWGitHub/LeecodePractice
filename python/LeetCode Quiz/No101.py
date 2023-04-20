from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root.left and not root.right:
            return True
        if not root.left or not root.right:
            return False

        return self.checkSymmetric(root.left, root.right)
    
    def checkSymmetric(self, node1, node2):
        if not node1 and not node2:
            return True
        if not node1 or not node2:
            return False
        
        print(node1.val, node2.val)

        return (node1.val==node2.val) and self.checkSymmetric(node1.left, node2.right) and self.checkSymmetric(node1.right, node2.left)

solution = Solution()
root = TreeNode(1, TreeNode(2, TreeNode(3), TreeNode(4)), TreeNode(2, TreeNode(4), TreeNode(3)))
print(solution.isSymmetric(root))