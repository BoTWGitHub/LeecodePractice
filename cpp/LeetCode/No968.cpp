/*
You are given the root of a binary tree. 
We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.
*/
#include <iostream>
#include <unordered_map>
#include "Debug\TreeNode.h"
using namespace std;

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        unordered_map<TreeNode*, vector<int>> mem;
        return dp(root, 0, mem);
    }
private:
    int dp(TreeNode* node, int state, unordered_map<TreeNode*, vector<int>>& mem){
        if(!node) return 0;
        if(mem.count(node) && mem[node][state]!=-1) return mem[node][state];

        int res;
        if(state==0){
            res = dp(node->left, 1, mem) + dp(node->right, 1, mem) + 1;
            if(node->left){
                res = min(res, dp(node->left, 2, mem) + dp(node->right, 0, mem) + 1);
            }
            if(node->right){
                res = min(res, dp(node->left, 0, mem) + dp(node->right, 2, mem) + 1);
            }
        }
        else{
            res = dp(node->left, state-1, mem) + dp(node->right, state-1, mem);
            if(node->left){
                res = min(res, dp(node->left, 2, mem) + dp(node->right, state-1, mem) + 1);
            }
            if(node->right){
                res = min(res, dp(node->left, state-1, mem) + dp(node->right, 2, mem) + 1);
            }
        }
        if(mem.count(node)==0) mem[node] = vector<int>(3, -1);
        return mem[node][state] = res;
    }
};

int main(void){
    Solution solution;
    TreeNode* root;

    root = new TreeNode(0, new TreeNode(0, new TreeNode(), new TreeNode()), nullptr);
    cout << solution.minCameraCover(root) << endl;

    root = new TreeNode(0, new TreeNode(0, new TreeNode(0, new TreeNode(0, nullptr, new TreeNode()), nullptr), nullptr), nullptr);
    cout << solution.minCameraCover(root) << endl;
    return 0;
}