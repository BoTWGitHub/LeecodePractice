'''
Given an integer n
, return all the structurally unique BST's (binary search trees)
, which has exactly n nodes of unique values from 1 to n. 

Return the answer in any order.
'''
from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        def backtrack(start: int, end: int) -> List[TreeNode]:
            if start>end:
                return [None,]
            
            res = []
            for i in range(start, end+1):
                left_trees = backtrack(start, i-1)
                right_trees = backtrack(i+1, end)
                
                for l in left_trees:
                    for r in right_trees:
                        root = TreeNode(i)
                        root.left = l
                        root.right = r
                        res.append(root)
            
            return res
        return backtrack(1, n)

def printPreorderTree(head: TreeNode):
    if not head:
        return
    printPreorderTree(head.left)
    print(f'{head.val},', end='')
    printPreorderTree(head.right)

def main():
    res = Solution.generateTrees(Solution(), 3)
    for tree in res:
        printPreorderTree(tree)
        print('')

if __name__=='__main__':
    main()
