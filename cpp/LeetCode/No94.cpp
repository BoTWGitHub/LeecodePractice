/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return res;
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        return res;
    }
    vector<int> inorderTraversal2(TreeNode* root) {
        if(!root) return res;
        stack<TreeNode*> mem;
        TreeNode* node = root;
        while(node || !mem.empty()){
            if(node){
                mem.push(node);
                node = node->left;
            }
            else{
                node = mem.top();
                mem.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};

int main(){
    Solution solution;
    TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    vector<int> res = solution.inorderTraversal2(root);

    cout << "[";
    for(int num : res) cout << num << ",";
    cout << "\b]" << endl;
    return 0;
}