/*
You are given a tree (i.e. a connected, undirected graph that has no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges. 
The root of the tree is the node 0, and each node of the tree has a label which is a lower-case character given in the string labels 
(i.e. The node with the number i has the label labels[i]).

The edges array is given on the form edges[i] = [ai, bi], which means there is an edge between nodes ai and bi in the tree.

Return an array of size n where ans[i] is the number of nodes in the subtree of the ith node which have the same label as node i.

A subtree of a tree T is the tree consisting of a node in T and all of its descendant nodes.
*/
#include <iostream>
#include <vector>
#include <array>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> ajList(n);
        for(vector<int>& edge : edges){
            ajList[edge[0]].push_back(edge[1]);
            ajList[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n);
        helper(0, -1, ajList, labels, res);
        return res;
    }
private:
    array<int, 26> helper(int node, int parent, vector<vector<int>>& ajList, string& labels, vector<int>& res){
        array<int, 26> temp = {0};
        temp[labels[node]-'a'] = 1;
        for(int neighbor : ajList[node]){
            if(neighbor==parent) continue;
            array<int, 26> childRes = helper(neighbor, node, ajList, labels, res);
            for(int i=0;i<26;i++) temp[i]+=childRes[i];
        }
        res[node] = temp[labels[node] - 'a'];
        return temp;
    }
};

int main(void){
    Solution solution;
    int n;
    vector<vector<int>> edges;
    string labels;
    vector<int> res;

    n = 7;
    edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    labels = "abaedcd";
    res = solution.countSubTrees(n, edges, labels);
    printVector(res);

    n = 4;
    edges = {{0,1},{1,2},{0,3}};
    labels = "bbbb";
    res = solution.countSubTrees(n, edges, labels);
    printVector(res);

    n = 5;
    edges = {{0,1},{0,2},{1,3},{0,4}};
    labels = "aabab";
    res = solution.countSubTrees(n, edges, labels);
    printVector(res);
    return 0;
}