/*
Given the root of a binary tree, the value of a target node target, and an integer k
, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
*/
#include <iostream>
#include <queue>
#include "Debug\VectorDebug.h"
#include "Debug\TreeNode.h"
using namespace std;

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res = distanceKFromTarget(target, k);
        if(root!=target && k!=0){
            int left = findNode(root->left, target);
            if(left==-1){
                int right = findNode(root->right, target);
                if(right>k){
                    vector<int> temp = distanceKFromTarget(root->right, right-k-1);
                    res.insert(res.end(), temp.begin(), temp.end());
                }
                else if(right<k){
                    vector<int> temp = distanceKFromTarget(root->left, k-right-1);
                    res.insert(res.end(), temp.begin(), temp.end());
                }
                else{
                    res.push_back(root->val);
                }
            }
            else{
                if(left>k){
                    vector<int> temp = distanceKFromTarget(root->left, left-k-1);
                    res.insert(res.end(), temp.begin(), temp.end());
                }
                else if(left<k){
                    vector<int> temp = distanceKFromTarget(root->right, k-left-1);
                    res.insert(res.end(), temp.begin(), temp.end());
                }
                else{
                    res.push_back(root->val);
                }
            }
        }
        
        return res;
    }
private:
    int findNode(TreeNode* node, TreeNode* target){
        if(!node) return -1;
        if(node==target) return 1;
        int left = findNode(node->left, target);
        int right = findNode(node->right, target);
        if(left!=-1) return left+1;
        if(right!=-1) return right+1;
        return -1;
    }
    vector<int> distanceKFromTarget(TreeNode* target, int k){
        if(!target) return {};
        if(k==0) return {target->val};
        queue<TreeNode*> q;
        q.push(target);
        int dis = 0;
        vector<int> res;
        while(!q.empty()){
            int size = q.size();
            dis++;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(dis==k){
                    if(node->left) res.push_back(node->left->val);
                    if(node->right) res.push_back(node->right->val);
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

int main(void){
    Solution solution;
    TreeNode* root;
    TreeNode* target;
    int k;
    vector<int> res;

    /*target = new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4)));
    root = new TreeNode(3, target, new TreeNode(1, new TreeNode(0), new TreeNode(8)));
    k = 2;
    res = solution.distanceK(root, target, k);
    printVector(res);

    target = new TreeNode(1);
    root = target;
    k = 3;
    res = solution.distanceK(root, target, k);
    printVector(res);*/

    target = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    root = new TreeNode(0, nullptr, target);
    k = 2;
    res = solution.distanceK(root, target, k);
    printVector(res);
    return 0;
}