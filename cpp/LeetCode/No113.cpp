/*
Given the root of a binary tree and an integer targetSum
, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
*/

#include <vector>
#include <iostream>

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
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        backtrack(root, targetSum, path);
        return result;
    }

    void backtrack(TreeNode *node, int target, vector<int> &path){
        if(!node){
            return;
        }
        path.push_back(node->val);
        if(!node->left && !node->right && node->val==target){
            result.push_back(path);
        }
        else{
            backtrack(node->left, target-node->val, path);
            backtrack(node->right, target-node->val, path);
        }
        path.pop_back();
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> result;

    TreeNode *root = new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr), new TreeNode(8, new TreeNode(13), new TreeNode(4, new TreeNode(5), new TreeNode(1))));
    int targetSum = 22;
    result = solution.pathSum(root, targetSum);

    cout << "[";
    for(vector<int> v : result){
        cout << "[";
        for(int num : v){
            cout << num << ",";
        }
        cout << "], ";
    }
    cout << "]" << endl;

    return 0;
}