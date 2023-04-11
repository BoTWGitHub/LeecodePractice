/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        stack<Node*> sk;
        sk.push(node);
        unordered_map<int, Node*> map;
        while(!sk.empty()){
            Node* cur = sk.top();
            sk.pop();
            if(map.count(cur->val)==0) map[cur->val] = new Node(cur->val);
            
            for(Node* neighbor : cur->neighbors){
                if(map.count(neighbor->val)==0){
                    Node* n = new Node(neighbor->val);
                    map[cur->val]->neighbors.push_back(n);
                    map[neighbor->val] = n;
                    sk.push(neighbor);
                }
                else{
                    map[cur->val]->neighbors.push_back(map[neighbor->val]);
                }
            }
        }
        return map[node->val];
    }
};

int main(void){

    return 0;
}