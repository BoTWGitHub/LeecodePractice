'''
Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.
'''

from typing import Optional
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        pair = []

        def getHeight(node: Optional[TreeNode]) -> int:
            if not node:
                return -1
            left = getHeight(node.left)
            right = getHeight(node.right)
            height = max(left, right)+1
            pair.append([height, node.val])
            return height

        getHeight(root)
        pair.sort()
        res = []
        for h, val in pair:
            if len(res)==h:
                res.append([val])
            else:
                res[h].append(val)
        return res

solution = Solution()
root = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))
#root = TreeNode(1, TreeNode(2), TreeNode(3))
print(solution.findLeaves(root))