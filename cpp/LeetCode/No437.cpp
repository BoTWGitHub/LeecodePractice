/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
*/
#include <iostream>
#include "Debug\TreeNode.h"
using namespace std;

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return helper(root, targetSum)+pathSum(root->left, targetSum)+pathSum(root->right, targetSum);
    }
private:
    int helper(TreeNode* node, int target){
        if(!node) return 0;
        return (node->val==target)+helper(node->left, target-node->val)+helper(node->right, target-node->val);
    }
};

int main(void){
    Solution solution;
    TreeNode* root;
    int targetSum;

    root = new TreeNode(10, new TreeNode(5, new TreeNode(3, new TreeNode(3), new TreeNode(-2)), new TreeNode(2, nullptr, new TreeNode(1))), new TreeNode(-3, nullptr, new TreeNode(11)));
    targetSum = 8;
    cout << solution.pathSum(root, targetSum) << endl;

    root = new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr), new TreeNode(8, new TreeNode(13), new TreeNode(4, new TreeNode(5), new TreeNode(1))));
    targetSum = 22;
    cout << solution.pathSum(root, targetSum) << endl;
    return 0;
}