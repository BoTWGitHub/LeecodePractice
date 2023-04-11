/*
Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. 
Each group of children is separated by the null value (See examples)
*/
#include <iostream>
#include "Debug\NaryTree.h"
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        for(Node* child : root->children){
            vector<int> temp = postorder(child);
            res.insert(res.end(), temp.begin(), temp.end());
        }
        res.push_back(root->val);
        return res;
    }
};

int main(){
    Solution solution;

    Node* root = new Node(1, {new Node(3, {new Node(5), new Node(6)}), new Node(2), new Node(4)});
    vector<int> res = solution.postorder(root);
    printVector(res);
    return 0;
}
