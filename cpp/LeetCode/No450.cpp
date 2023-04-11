/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
*/
#include <iostream>
#include "Debug\TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key){
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            TreeNode* next = findSuccessor(root);
            root->val = next->val;
            root->right = deleteNode(root->right, next->val);
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
private:
    TreeNode* findSuccessor(TreeNode* root){
        TreeNode* cur = root->right;
        while(cur && cur->left){
            cur = cur->left;
        }
        return cur;
    }
};

int main(){
    Solution solution;

    TreeNode* root = new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6, nullptr, new TreeNode(7)));
    root->printTree();

    root = solution.deleteNode(root, 3);
    root->printTree();
    return 0;
}
