'''
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

   The left subtree of a node contains only nodes with keys less than the node's key.
   The right subtree of a node contains only nodes with keys greater than the node's key.
   Both the left and right subtrees must also be binary search trees.
'''
from typing import Optional, List
import math

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def travelTree(root: Optional[TreeNode], order: List[int]):
            if not root:
                return
            travelTree(root.left, order)
            order.append(root.val)
            travelTree(root.right, order)
        
        temp = []
        travelTree(root, temp)
        print(temp)
        for i in range(1, len(temp)):
            if temp[i]<=temp[i-1]:
                return False
        return True

    def isValidBST2(self, root: Optional[TreeNode]) -> bool:
        def validate(node, high = math.inf, low = -math.inf):
            if not node:
                return True
            if node.val<=low or node.val>=high:
                return False
            return validate(node.right, high, node.val) and validate(node.left, node.val, low)
        return validate(root)

def main():
    solution = Solution()
    #root = TreeNode(5, TreeNode(1), TreeNode(4, TreeNode(3), TreeNode(6)))
    root = TreeNode(4, TreeNode(2, TreeNode(1), TreeNode(3)), TreeNode(6, TreeNode(5), TreeNode(7)))
    print(solution.isValidBST2(root))

if __name__=='__main__':
    main()