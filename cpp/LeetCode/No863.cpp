/*
Given the root of a binary tree, the value of a target node target, and an integer k
, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
*/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "Debug\VectorDebug.h"
#include "Debug\TreeNode.h"
using namespace std;

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentOf;
        vector<int> res;
        parentOf[root] = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parentOf[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parentOf[node->right] = node;
                q.push(node->right);
            }
        }
        int dis = 0;
        unordered_set<int> seen;
        seen.insert(target->val);
        q.push(target);
        while(!q.empty()){
            if(dis==k){
                while(!q.empty()){
                    res.push_back(q.front()->val);
                    q.pop();
                }
            }
            else{
                int size = q.size();
                for(int i=0;i<size;i++){
                    TreeNode* node = q.front();
                    q.pop();
                    if(node->left && seen.count(node->left->val)==0){
                        seen.insert(node->left->val);
                        q.push(node->left);
                    }
                    if(node->right && seen.count(node->right->val)==0){
                        seen.insert(node->right->val);
                        q.push(node->right);
                    }
                    if(parentOf[node] && seen.count(parentOf[node]->val)==0){
                        seen.insert(parentOf[node]->val);
                        q.push(parentOf[node]);
                    }
                }
            }
            dis++;
        }
        return res;
    }
};

int main(void){
    Solution solution;
    TreeNode* root;
    TreeNode* target;
    int k;
    vector<int> res;

    target = new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4)));
    root = new TreeNode(3, target, new TreeNode(1, new TreeNode(0), new TreeNode(8)));
    k = 2;
    res = solution.distanceK(root, target, k);
    printVector(res);

    target = new TreeNode(1);
    root = target;
    k = 3;
    res = solution.distanceK(root, target, k);
    printVector(res);

    target = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    root = new TreeNode(0, nullptr, target);
    k = 2;
    res = solution.distanceK(root, target, k);
    printVector(res);
    return 0;
}