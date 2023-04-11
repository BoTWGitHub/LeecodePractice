/*
Given the root of a binary tree, return the level order traversal of its nodes' values. 
(i.e., from left to right, level by level).
*/
#include <iostream>
#include <vector>
#include <queue>
#include "Debug\TreeNode.h"
#include "Debug\VectorDebug.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            vector<int> temp;
            int len = q.size();
            for(int i=0;i<len;i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main(){
    Solution solution;

    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    print2DVector<int>(solution.levelOrder(root));
    return 0;
}
