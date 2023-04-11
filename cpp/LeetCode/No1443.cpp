/*
Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. 
You spend 1 second to walk over one edge of the tree. 
Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. 
Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> ajList(n);
        for(vector<int>& edge : edges){
            ajList[edge[0]].push_back(edge[1]);
            ajList[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        dfs(0, -1, ajList, hasApple, res);
        return res*2;
    }
private:
    bool dfs(int node, int parent, vector<vector<int>>& ajList, vector<bool>& hasApple, int& path){
        bool res = hasApple[node];
        
        for(int neighbor : ajList[node]){
            if(neighbor!=parent){
                if(dfs(neighbor, node, ajList, hasApple, path)){
                    path++;
                    res = true;
                }
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    int n;
    vector<vector<int>> edges;
    vector<bool> hasApple;

    n = 7;
    edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    hasApple = {false,false,true,false,true,true,false};
    cout << solution.minTime(n, edges, hasApple) << endl;

    n = 7;
    edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    hasApple = {false,false,true,false,false,true,false};
    cout << solution.minTime(n, edges, hasApple) << endl;

    n = 7;
    edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    hasApple = {false,false,false,false,false,false,false};
    cout << solution.minTime(n, edges, hasApple) << endl;
    return 0;
}