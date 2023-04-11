/*
There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.
*/
#include <iostream>
#include "Debug\VectorDebug.h"
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> ajList(n);
        for(vector<int>& edge : edges){
            ajList[edge[0]].push_back(edge[1]);
            ajList[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n, 0);
        vector<int> count(n, 1);
        dfs(ajList, 0, -1, count, res);
        dfs2(ajList, 0, -1, count, res);
        return res;
    }
private:
    void dfs(vector<vector<int>>& ajList, int node, int last, vector<int>& count, vector<int>& res){
        for(int neighbor : ajList[node]){
            if(neighbor!=last){
                dfs(ajList, neighbor, node, count, res);
                count[node]+=count[neighbor];
                res[node]+=res[neighbor]+count[neighbor];
            }
        }
    }
    void dfs2(vector<vector<int>>& ajList, int node, int last, vector<int>& count, vector<int>& res){
        for(int neighbor : ajList[node]){
            if(neighbor!=last){
                res[neighbor] = res[node]-2*count[neighbor]+ajList.size();
                dfs2(ajList, neighbor, node, count, res);
            }
        }
    }
};

int main(void){
    Solution solution;
    int n;
    vector<vector<int>> edges;
    vector<int> res;

    n = 6;
    edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    res = solution.sumOfDistancesInTree(n, edges);
    printVector(res);

    n = 1;
    edges = {};
    res = solution.sumOfDistancesInTree(n, edges);
    printVector(res);

    n = 2;
    edges = {{1,0}};
    res = solution.sumOfDistancesInTree(n, edges);
    printVector(res);
    return 0;
}