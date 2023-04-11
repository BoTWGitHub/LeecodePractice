/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1
, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i 
(i.e., there is a directed edge from node i to node graph[i][j]).
*/
#include <iostream>
#include <vector>
#include <stack>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        stack<vector<int>> sk;
        sk.push({0});
        vector<vector<int>> res;
        while(!sk.empty()){
            vector<int> path = sk.top();
            sk.pop();
            for(int neighbor : graph[path.back()]){
                vector<int> p = path;
                p.push_back(neighbor);
                if(neighbor==graph.size()-1) res.push_back(p);
                else sk.push(p);
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> graph;
    vector<vector<int>> res;

    graph = {{1,2},{3},{3},{}};
    res = solution.allPathsSourceTarget(graph);
    print2DVector(res);

    graph = {{4,3,1},{3,2,4},{3},{4},{}};
    res = solution.allPathsSourceTarget(graph);
    print2DVector(res);

    graph = {{1,2,3},{2},{3},{}};
    res = solution.allPathsSourceTarget(graph);
    print2DVector(res);

    return 0;
}