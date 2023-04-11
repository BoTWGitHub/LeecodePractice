/*
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal
, each group of children is separated by the null value (See examples).
*/
#include <iostream>
#include "Debug\NaryTree.h"

using namespace std;

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int res = 0;
        for(Node* child : root->children){
            int temp = maxDepth(child);
            res = max(res, temp);
        }
        return res+1;
    }
};

int main(){
    Solution solution;

    Node* root = new Node(1, {new Node(3, {new Node(5), new Node(6)}), new Node(2), new Node(4)});
    cout << solution.maxDepth(root) << endl;
    return 0;
}
