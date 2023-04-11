/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
*/
#include <iostream>
#include <vector>
#include "Debug\TreeNode.h"
using namespace std;

class Solution {
public:
    int rob(TreeNode* root) {
        
    }
};

int main(void){
    Solution solution;
    TreeNode* root;

    root = new TreeNode(3, new TreeNode(2, nullptr, new TreeNode(3)), new TreeNode(3, nullptr, new TreeNode(1)));
    return 0;
}