'''
You are given the root of a binary tree with n nodes.
Each node is uniquely assigned a value from 1 to n.
You are also given an integer startValue representing the value of the start node s
, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t.
Generate step-by-step directions of such path as a string consisting of only the uppercase letters
'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        self.path = ''
        def findNode(node: TreeNode, val: int):
            if not node:
                return False
            if node.val == val:
                return True
            left = findNode(node.left, val)
            right = findNode(node.right, val)
            if left:
                self.path = 'L' + self.path
            if right:
                self.path = 'R' + self.path
            return left or right
        findNode(root, startValue)
        start_path = self.path
        self.path = ''
        findNode(root, destValue)
        dest_path = self.path

        while len(start_path) and len(dest_path):
            if start_path[0] == dest_path[0]:
                start_path = start_path[1:]
                dest_path = dest_path[1:]
            else:
                break

        start_path = 'U' * len(start_path)

        return start_path+dest_path

solution = Solution()

root = TreeNode(5, TreeNode(1, TreeNode(3)), TreeNode(2, TreeNode(6), TreeNode(4)))
startV = 1
destV = 4
print(solution.getDirections(root, startV, destV))