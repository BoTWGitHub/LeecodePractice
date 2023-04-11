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
    
    void printTree(){
        TreeNode* node = this;
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur){
                    cout << cur->val << ",";
                    q.push(cur->left);
                    q.push(cur->right);
                }
                else{
                    cout << "None,";
                }
            }
            cout << endl;
        }
    }
};