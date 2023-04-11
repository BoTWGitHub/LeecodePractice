/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
#include <iostream>
#include "Debug\TreeNode.h"
using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return false;
        return validate(root, nullptr, nullptr);
    }
private:
    bool validate(TreeNode* node, TreeNode* upper, TreeNode* lower){
        if(!node) return true;
        if(upper && node->val>=upper->val || lower && node->val<=lower->val) return false;
        return validate(node->left, node, lower) && validate(node->right, upper, node);
    }
};

int main(){
    Solution solution;

    TreeNode* root = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
    cout << solution.isValidBST(root) << endl;
    return 0;
}
