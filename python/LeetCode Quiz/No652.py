'''
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.
'''
from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        def dfs(node: TreeNode, mem: dict, res: List[TreeNode]) -> str:
            if not node:
                return 'N'
            left, right = dfs(node.left, mem, res), dfs(node.right, mem, res)
            path = str(node.val) + '-' + left + '-' + right
            if path not in mem:
                mem[path] = 1
            else:
                mem[path]+=1
                if mem[path]==2:
                    res.append(node)
            return path

        result = []
        dfs(root, dict(), result)

        return result

def printTree(root: TreeNode):
    if not root:
        print('-', end='')
        return
    printTree(root.left)
    print(root.val, end='')
    printTree(root.right)

def main():
    root = TreeNode(2, TreeNode(1, TreeNode(11)), TreeNode(11, TreeNode(1)))
    res = Solution.findDuplicateSubtrees(Solution(), root)
    for node in res:
        printTree(node)
        print('')

if __name__=='__main__':
    main()
