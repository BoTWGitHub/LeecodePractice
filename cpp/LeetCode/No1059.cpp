/*
Given the edges of a directed graph where edges[i] = [ai, bi] indicates there is an edge between nodes ai and bi
, and two nodes source and destination of this graph, determine whether or not all paths starting from source eventually, end at destination
, that is:

 - At least one path exists from the source node to the destination node

 - If a path exists from the source node to a node with no outgoing edges, then that node is equal to destination.

 - The number of possible paths from source to destination is a finite number.

Return true if and only if all roads from source lead to destination.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> ajList(n);
        for(vector<int> edge : edges) ajList[edge[0]].push_back(edge[1]);
        vector<bool> seen(n, false);
        vector<bool> mem(n, false);
        return dp(source, ajList, seen, destination, mem);
    }
private:
    bool dp(int node, vector<vector<int>> &ajList, vector<bool> &seen, int destination, vector<bool> &mem){
        if(node==destination) return ajList[node].empty();
        if(mem[node]) return mem[node];

        if(ajList[node].empty()) return false;
        seen[node] = true;
        for(int neighbor : ajList[node]){
            if(seen[neighbor] || !dp(neighbor, ajList, seen, destination, mem)) return false;
        }
        seen[node] = false;
        return mem[node] = true;
    }
};

int main(void){
    Solution solution;
    int n;
    vector<vector<int>> edges;
    int source, destination;

    n = 3;
    edges = {{0,1},{0,2}};
    source = 0;
    destination = 2;
    cout << solution.leadsToDestination(n, edges, source, destination) << endl;

    n = 4;
    edges = {{0,1},{0,3},{1,2},{2,1}};
    source = 0;
    destination = 3;
    cout << solution.leadsToDestination(n, edges, source, destination) << endl;

    n = 4;
    edges = {{0,1},{0,2},{1,3},{2,3}};
    source = 0;
    destination = 3;
    cout << solution.leadsToDestination(n, edges, source, destination) << endl;

    n = 2;
    edges = {{0,1},{1,1}};
    source = 0;
    destination = 1;
    cout << solution.leadsToDestination(n, edges, source, destination) << endl;
    return 0;
}