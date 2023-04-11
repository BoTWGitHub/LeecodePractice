/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”
*/
#include <iostream>
#include "Debug\TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};

int main(){
    Solution solution;

    TreeNode* root = new TreeNode(6, new TreeNode(2, new TreeNode(0), new TreeNode(4, new TreeNode(3), new TreeNode(5))), new TreeNode(8, new TreeNode(7), new TreeNode(9)));
    TreeNode* res = solution.lowestCommonAncestor(root, root->left, root->right);
    cout << res->val << endl;
    return 0;
}
