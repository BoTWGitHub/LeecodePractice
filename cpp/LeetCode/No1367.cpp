/*
Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head 
correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.
*/
#include <iostream>
#include "Debug\ListNode.h"
#include "Debug\TreeNode.h"
#include <queue>
using namespace std;

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode*> candidate;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val==head->val) candidate.push_back(node);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        for(TreeNode* node : candidate){
            if(helper(head, node)) return true;
        }
        return false;
    }
private:
    bool helper(ListNode* list, TreeNode* node){
        if(!list) return true;
        if(!node) return false;
        if(node->val != list->val) return false;
        return helper(list->next, node->left)|helper(list->next, node->right);
    }
};

int main(void){
    Solution solution;
    ListNode* head;
    TreeNode* root;

    head = constructListByArray({4,2,8});
    root = new TreeNode(1, new TreeNode(4, nullptr, new TreeNode(2, new TreeNode(1), nullptr)), new TreeNode(4, new TreeNode(2, new TreeNode(6), new TreeNode(8, new TreeNode(1), new TreeNode(3))), nullptr));
    cout << solution.isSubPath(head, root) << endl;

    head = constructListByArray({1,4,2,6});
    root = new TreeNode(1, new TreeNode(4, nullptr, new TreeNode(2, new TreeNode(1), nullptr)), new TreeNode(4, new TreeNode(2, new TreeNode(6), new TreeNode(8, new TreeNode(1), new TreeNode(3))), nullptr));
    cout << solution.isSubPath(head, root) << endl;

    head = constructListByArray({1,4,2,6,8});
    root = new TreeNode(1, new TreeNode(4, nullptr, new TreeNode(2, new TreeNode(1), nullptr)), new TreeNode(4, new TreeNode(2, new TreeNode(6), new TreeNode(8, new TreeNode(1), new TreeNode(3))), nullptr));
    cout << solution.isSubPath(head, root) << endl;
    return 0;
}