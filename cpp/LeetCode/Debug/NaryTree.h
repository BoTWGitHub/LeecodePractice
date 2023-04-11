#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

/* Definition for a Node.*/
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
    void printNaryTree(){
        Node* root = this;
        string res = "";
        nodeToString(root, res);
        cout << "[" << res << "]" << endl;
    }
private:
    void nodeToString(Node* node, string& res){
        if(!node) return;
        res+=to_string(node->val);
        if(node->children.size()>0) res+="[";
        for(Node* child : node->children){
            nodeToString(child, res);
            res+=" ";
        }
        if(node->children.size()>0) res.back() = ']';
    }
};