/*
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.
*/
#include <iostream>
#include <queue>
#include "Debug\TreeNode.h"
using namespace std;

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int last = 0;
        while(!q.empty()){
            auto [node, i] = q.front();
            q.pop();
            if(i-last>1) return false;
            last = i;
            if(node->left) q.push({node->left, i*2});
            if(node->right) q.push({node->right, i*2+1});
        }
        return true;
    }
};

int main(void){
    Solution solution;
    TreeNode* root;

    root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), nullptr));
    cout << solution.isCompleteTree(root) << endl;

    root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, nullptr, new TreeNode(7)));
    cout << solution.isCompleteTree(root) << endl;
    return 0;
}