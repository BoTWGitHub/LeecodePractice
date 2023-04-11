/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/
#include <iostream>
#include <queue>

using namespace std;

/* Definition for a binary tree node. */
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
    bool isSameTree2(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> que;
        que.push(p);
        que.push(q);
        while(!que.empty()){
            p = que.front();
            que.pop();
            q = que.front();
            que.pop();
            if(!p && !q);
            else if(!p || !q) return false;
            else if(p->val != q->val) return false;
            else{
                que.push(p->left);
                que.push(q->left);
                que.push(p->right);
                que.push(q->right);
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    
    TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode *q = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    cout << solution.isSameTree2(p, q) << endl;

    return 0;
}
