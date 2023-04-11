/*
You have a graph of n nodes labeled from 0 to n - 1. 
You are given an integer n and a list of edges where edges[i] = [ai, bi] 
indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include "Debug\UnionFind.h"
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        UnionFind uf(n);
        for(vector<int> edge : edges){
            if(uf.find(edge[0])==uf.find(edge[1])) return false;
                uf.connect(edge[0], edge[1]);
        }
        return uf.getNumOfGroup()==1;
    }
};

int main(void){
    Solution solution;
    int n;
    vector<vector<int>> edges;

    n=5;
    edges = {{0,1},{0,2},{0,3},{1,4}};
    cout << solution.validTree(n, edges) << endl;

    n=5;
    edges = {{0,1},{1,2},{2,3},{1,3},{1,4}};
    cout << solution.validTree(n, edges) << endl;

    return 0;
}