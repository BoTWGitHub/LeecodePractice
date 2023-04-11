/*
Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal
, each group of children is separated by the null value (See examples).
*/
#include <iostream>
#include "Debug\NaryTree.h"
#include "Debug\VectorDebug.h"
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                temp.push_back(node->val);
                for(Node* child : node->children){
                    q.push(child);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main(){
    Solution solution;

    Node* root = new Node(1, {new Node(3, {new Node(5), new Node(6)}), new Node(2), new Node(4)});
    vector<vector<int>> res = solution.levelOrder(root);
    print2DVector(res);
    return 0;
}
