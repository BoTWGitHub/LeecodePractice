/*
Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. 
For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

We want to do the transformation in place. 
After the transformation, the left pointer of the tree node should point to its predecessor, 
and the right pointer should point to its successor. 
You should return the pointer to the smallest element of the linked list.
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/* Definition for a Node.*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node() {}
    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }
    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
    void printTree(){
        Node* cur = this;
        stack<Node*> sk;
        while(cur || !sk.empty()){
            if(cur){
                sk.push(cur);
                cur = cur->left;
            }
            else{
                cur = sk.top();
                sk.pop();
                cout << cur->val << ", ";
                cur = cur->right;
            }
        }
        cout << endl;
    }
    void printList(){
        Node* head = this;
        Node* cur = this;
        while(cur){
            cout << cur->val << " -> ";
            cur = cur->right;
            if(cur == head) break;
        }
        cout << endl;
    }
    void printRevList(){
        Node* head = this;
        Node* cur = this;
        while(cur){
            cout << cur->val << " -> ";
            cur = cur->left;
            if(cur == head) break;
        }
        cout << endl;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        traverseTree(root);
        first->left = last;
        last->right = first;
        return first;
    }
    void traverseTree(Node* n){
        if(!n) return;
        cout << n->val << endl;
        traverseTree(n->left);
        if(!last){
            first = n;
        }
        else{
            last->right = n;
            n->left = last;
        }
        last = n;
        traverseTree(n->right);
    }
private:
    Node* first = nullptr;
    Node* last = nullptr;
};

int main(){
    Solution solution;
    Node* root = new Node(4, new Node(2, new Node(1), new Node(3)), new Node(5));
    root->printTree();
    Node* head = solution.treeToDoublyList(root);
    head->printList();
    head->printRevList();
    return 0;
}
