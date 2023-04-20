'''
Given the root of a binary tree and an integer targetSum
, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
'''
from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        def backtrack(node: TreeNode, path: List[int] = [], target:int = targetSum):
            if not node:
                return
            path.append(node.val)
            if target==node.val and not node.left and not node.right:
                res.append(path.copy())
            else:
                backtrack(node.left, path, target-node.val)
                backtrack(node.right, path, target-node.val)
            path.pop()

        res = []
        backtrack(root)
        return res

def main():
    solution = Solution()

    root = TreeNode(5, TreeNode(4, TreeNode(11, TreeNode(7), TreeNode(2))), TreeNode(8, TreeNode(13), TreeNode(4, TreeNode(5), TreeNode(1))))
    #root = TreeNode(-2, None, TreeNode(-3))
    targetSum = 22
    print(solution.pathSum(root, targetSum))

if __name__=='__main__':
    main()
