/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.
*/
#include <iostream>
#include "Debug\TreeNode.h"
#include <queue>

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(!node->left && !node->right) return res;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right); 
            }
            res++;
        }
        return res;
    }
};

int main(){
    Solution solution;

    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout << solution.minDepth(root) << endl;
    return 0;
}
