/*
You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.
*/
#include <iostream>
#include "Debug\TreeNode.h"
using namespace std;

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int res = 0;
        if(root->left) helper(root->left, true, 1, res);
        if(root->right) helper(root->right, false, 1, res);
        return res;
    }
private:
    void helper(TreeNode* node, bool left, int len, int& res){
        res = max(res, len);
        if(left){
            if(node->right) helper(node->right, false, len+1, res);
            if(node->left) helper(node->left, true, 1, res);
        }
        else{
            if(node->right) helper(node->right, false, 1, res);
            if(node->left) helper(node->left, true, len+1, res);
        }
    }
};

int main(void){
    Solution solution;
    TreeNode* root;

    root = new TreeNode(1, nullptr, new TreeNode(1, new TreeNode(1), new TreeNode(1, new TreeNode(1, nullptr, new TreeNode(1, nullptr, new TreeNode(1))), new TreeNode(1))));
    cout << solution.longestZigZag(root) << endl;
    
    root = new TreeNode(1, new TreeNode(1, nullptr, new TreeNode(1, new TreeNode(1, nullptr, new TreeNode(1)), new TreeNode(1))), new TreeNode(1));
    cout << solution.longestZigZag(root) << endl;

    root = new TreeNode(1);
    cout << solution.longestZigZag(root) << endl;
    return 0;
}