'''
Given the root of a binary tree
, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way
, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.
'''
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        if not root:
            return ''
        if not root.left and not root.right:
            return f'{root.val}'
        elif root.left and not root.right:
            return f'{root.val}({self.tree2str(root.left)})'
        elif not root.left and root.right:
            return f'{root.val}()({self.tree2str(root.right)})'
        else:
            return f'{root.val}({self.tree2str(root.left)})({self.tree2str(root.right)})'


def main():
    solution = Solution()

    root = TreeNode(1, TreeNode(2, TreeNode(4)), TreeNode(3))
    print(solution.tree2str(root))

if __name__=='__main__':
    main()
