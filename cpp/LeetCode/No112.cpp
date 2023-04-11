/*
Given the root of a binary tree and an integer targetSum
, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
*/
#include <iostream>

using namespace std;

/* Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(targetSum==root->val && !root->left && !root->right) return true;

        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};

int main(){
    Solution solution;

    TreeNode* root = new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr), new TreeNode(8, new TreeNode(13), new TreeNode(4, nullptr, new TreeNode(1))));
    int targetSum = 25;
    cout << solution.hasPathSum(root, targetSum) << endl;
    return 0;
}
