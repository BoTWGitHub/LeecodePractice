/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer
, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. 
An N-ary tree is a rooted tree in which each node has no more than N children. 
There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.
*/
#include <iostream>
#include <string>
#include <stack>
#include "Debug\NaryTree.h"

using namespace std;

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(!root) return "[]";
        string res = "";
        nodeToString(root, res);
        return "[" + res + "]";
    }
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data == "[]") return nullptr;
        int i = 1;
        string temp = "";
        while(data[i]!=']' && data[i] !='[') temp.push_back(data[i++]);
        Node* root = new Node(stoi(temp));
        if(data[i]==']') return root;
        i++;
        temp = "";
        stack<Node*> s;
        s.push(root);
        Node* cur;
        Node* child;
        while(!s.empty()){
            cur = s.top();
            switch(data[i]){
                case ' ':
                    if(temp!=""){
                        cur->children.push_back(new Node(stoi(temp)));
                        temp = "";
                    }
                    break;

                case '[':
                    child = new Node(stoi(temp));
                    cur->children.push_back(child);
                    s.push(child);
                    temp = "";
                    break;
                
                case ']':
                    if(temp!=""){
                        cur->children.push_back(new Node(stoi(temp)));
                        temp = "";
                    }
                    s.pop();
                    break;
                
                default:
                    temp.push_back(data[i]);
                    break;
            }
            i++;
        }
        return root;
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

int main(){
    Codec c;

    Node* root = new Node(1, {new Node(3, {new Node(5), new Node(6)}), new Node(2), new Node(4)});
    string encode = c.serialize(root);
    cout << encode << endl;

    Node* newRoot = c.deserialize(encode);
    newRoot->printNaryTree();
    return 0;
}
