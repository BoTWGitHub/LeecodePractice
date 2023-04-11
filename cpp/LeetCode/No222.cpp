/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree
, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
*/
#include <iostream>
#include <cmath>
#include "Debug\TreeNode.h"
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* cur = root;
        int h = 0;
        while(cur->left){
            cur = cur->left;
            h++;
        }
        if(h==0) return 1;
        return bSearch(root, pow(2, h), pow(2, h+1)-1, h);
    }
private:
    int bSearch(TreeNode* root, int left, int right, int h){
        TreeNode* cur;
        while(left<right){
            int mid = (right-left)/2 + left +(right-left)%2;
            vector<bool> path(h, false);
            int temp = mid;
            int index = h-1;
            while(temp>1){
                if(temp%2){
                    path[index] = true;
                }
                index--;
                temp/=2;
            }
            cur = root;
            for(int i=0;i<h;i++){
                if(path[i]) cur = cur->right;
                else cur = cur->left;
            }
            if(cur) left = mid;
            else right = mid-1;
        }
        return left;
    }
};

int main(void){
    Solution solution;
    TreeNode* root;

    root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), nullptr));
    cout << solution.countNodes(root) << endl;

    root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    cout << solution.countNodes(root) << endl;
    return 0;
}