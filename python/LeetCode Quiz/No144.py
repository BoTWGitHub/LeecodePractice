'''
Given the root of a binary tree, return the preorder traversal of its nodes' values.
'''

from typing import Optional
from typing import List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        return [root.val] + self.preorderTraversal(root.left) + self.preorderTraversal(root.right)

solution = Solution()
root = TreeNode(1, None, TreeNode(2, TreeNode(3)))
print(solution.preorderTraversal(root))