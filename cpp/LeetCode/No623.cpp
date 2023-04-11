/*
Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1
, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all
, then create a tree node with value val as the new root of the whole original tree
, and the original tree is the new root's left subtree.
*/
#include <iostream>
#include <vector>
#include <queue>
#include "Debug/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node = new TreeNode(val, root, nullptr);
            return node;
        }
        
        vector<TreeNode*> nodes = getDepth(root, depth);
        for(TreeNode* node : nodes){
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            node->left = new TreeNode(val, left, nullptr);
            node->right = new TreeNode(val, nullptr, right);
        }

        return root;
    }
private:
    vector<TreeNode*> getDepth(TreeNode* root, int depth){
        if(depth==2) return {root};
        vector<TreeNode*> res;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            level++;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(level==depth-1){
                    if(node->left) res.push_back(node->left);
                    if(node->right) res.push_back(node->right);
                }
                else{
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution solution;

    TreeNode* root = new TreeNode(4, new TreeNode(2, new TreeNode(3), new TreeNode(1)), new TreeNode(6, new TreeNode(5), nullptr));
    int val = 1, depth = 3;
    TreeNode* res = solution.addOneRow(root, val, depth);

    res->printTree();
    return 0;
}
