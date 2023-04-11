/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
*/
#include <iostream>
#include <cmath>
#include "Debug\TreeNode.h"

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left = getHeight(root->left), right = getHeight(root->right);
        if(abs(left-right)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int getHeight(TreeNode* node){
        if(!node) return 0;
        return max(getHeight(node->left), getHeight(node->right))+1;
    }
};

int main(){
    Solution solution;

    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4), nullptr), nullptr), new TreeNode(2, nullptr, new TreeNode(3, nullptr, new TreeNode(4))));
    cout << solution.isBalanced(root) << endl;

    return 0;
}
