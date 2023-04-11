/*
Given the root of a binary search tree and a node p in it, return the in-order successor of that node in the BST. 
If the given node has no in-order successor in the tree, return null.

The successor of a node p is the node with the smallest key greater than p.val.
*/
#include <iostream>
#include <vector>
#include "Debug\TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = nullptr;
        while(root){
            if(p->val >= root->val){
                root = root->right;
            }
            else{
                res = root;
                root = root->left;
            }
        }
        return res;
    }
};

int main(){
    return 0;
}
