/*
Design an algorithm to encode an N-ary tree into a binary tree and decode the binary tree to get the original N-ary tree. 
An N-ary tree is a rooted tree in which each node has no more than N children. 
Similarly, a binary tree is a rooted tree in which each node has no more than 2 children. 
There is no restriction on how your encode/decode algorithm should work. 
You just need to ensure that an N-ary tree can be encoded to a binary tree and this binary tree can be decoded to the original N-nary tree structure.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See following example).
*/
#include <iostream>
#include "Debug\NaryTree.h"
#include "Debug\TreeNode.h"

using namespace std;

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(!root) return nullptr;
        TreeNode* node = new TreeNode(root->val);
        node->right = naryTreeToBinTree(root);
        return node;
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(!root) return nullptr;
        Node* node = new Node(root->val);
        node->children = binTreeToNaryTree(root);
        return node;
    }
private:
    TreeNode* naryTreeToBinTree(Node* parent){
        int size = parent->children.size();
        if(size==0) return nullptr;
        TreeNode* root = new TreeNode(parent->children[0]->val);
        TreeNode* bnode = root;
        for(int i=0;i<size;i++){
            Node* cur = parent->children[i];
            bnode->right = naryTreeToBinTree(cur);
            if(i+1<size){
                bnode->left = new TreeNode(parent->children[i+1]->val);
                bnode = bnode->left;
            }
        }
        return root;
    }
    vector<Node*> binTreeToNaryTree(TreeNode* parent){
        vector<Node*> res;
        if(!parent->right) return res;
        TreeNode* tree = parent->right;
        while(tree){
            res.push_back(new Node(tree->val, binTreeToNaryTree(tree)));
            tree = tree->left;
        }
        return res;
    }
};

int main(){
    Codec c;

    Node* root = new Node(1, {new Node(3, {new Node(5), new Node(6)}), new Node(2), new Node(4)});
    root->printNaryTree();

    TreeNode* tree = c.encode(root);
    tree->printTree();

    Node* newRoot = c.decode(tree);
    newRoot->printNaryTree();

    return 0;
}
