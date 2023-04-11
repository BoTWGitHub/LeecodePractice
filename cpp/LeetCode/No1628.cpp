/*
Given the postfix tokens of an arithmetic expression, build and return the binary expression tree that represents this expression.
*/
#include <iostream>
#include <vector>
#include <string>
#include "Debug\VectorDebug.h"
using namespace std;

/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */
class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;

protected:
    // define your fields here
};

class NumNode: public Node{
public:
    NumNode(int val){
        this->val = val;
    }
    int evaluate() const{
        return val;
    }
protected:
    int val;
};

class OpNode: public Node{
public:
    OpNode(char op, Node* left, Node* right){
        this->op = op;
        this->left = left;
        this->right = right;
    }
    int evaluate() const{
        switch(op){
            case '+':
                return left->evaluate()+right->evaluate();
            case '-':
                return left->evaluate()-right->evaluate();
            case '*':
                return left->evaluate()*right->evaluate();
            case '/':
                return left->evaluate()/right->evaluate();
            default:
                cout << "error" << endl;
                return 0;
        }
    }
protected:
    char op;
    Node* left = nullptr;
    Node* right = nullptr;
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */
class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        if(postfix.size()==0) return nullptr;
        if(isdigit(postfix.back()[0])){
            int val = stoi(postfix.back());
            postfix.pop_back();
            return new NumNode(val);
        }
        else{
            char op = postfix.back()[0];
            postfix.pop_back();
            Node* r = buildTree(postfix);
            Node* l = buildTree(postfix);
            return new OpNode(op, l, r);
        }
    }
};

/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
int main(void){
    TreeBuilder* obj = new TreeBuilder();
    Node* node;
    vector<string> postfix;

    postfix = {"3","4","+","2","*","7","/"};
    node = obj->buildTree(postfix);
    cout << node->evaluate() << endl;

    postfix = {"4","5","2","7","+","-","*"};
    node = obj->buildTree(postfix);
    cout << node->evaluate() << endl;
    return 0;
}