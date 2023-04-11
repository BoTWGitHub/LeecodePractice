/*
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.
*/
#include <iostream>
#include "Debug\TreeNode.h"
using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        if(root) helper(root, 0, res);
        return res;
    }
private:
    void helper(TreeNode* node, int last, int& res){
        if(!node->left && !node->right){
            res+=(last*10+node->val);
            return;
        }
        if(node->left) helper(node->left, last*10+node->val, res);
        if(node->right) helper(node->right, last*10+node->val, res);
    }
};

int main(void){
    Solution solution;
    TreeNode* root;

    root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << solution.sumNumbers(root) << endl;

    root = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    cout << solution.sumNumbers(root) << endl;
    return 0;
}