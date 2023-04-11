/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
A node can only appear in the sequence at most once. 
Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/
#include <iostream>
#include "Debug\TreeNode.h"
#include <climits>
using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return INT_MIN;
        if(!root->left && !root->right) return root->val;
        int leftMax = 0;
        maxSum(root->left, 0, leftMax);
        int rightMax = 0;
        maxSum(root->right, 0, rightMax);
        int res = root->val+leftMax+rightMax;
        res = max(res, max(maxPathSum(root->left), maxPathSum(root->right)));
        return res;
    }
private:
    void maxSum(TreeNode* node, int temp, int& res){
        if(!node) return;
        res = max(res, temp+node->val);

        maxSum(node->left, temp+node->val, res);
        maxSum(node->right, temp+node->val, res);
    }
};

int main(void){
    Solution solution;
    TreeNode* root;

    root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << solution.maxPathSum(root) << endl;

    root = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout << solution.maxPathSum(root) << endl;

    root = new TreeNode(1, new TreeNode(2), nullptr);
    cout << solution.maxPathSum(root) << endl;

    root = new TreeNode(-1, new TreeNode(5, new TreeNode(4, nullptr, new TreeNode(2, new TreeNode(-4), nullptr)), nullptr), nullptr);
    cout << solution.maxPathSum(root) << endl;
    return 0;
}