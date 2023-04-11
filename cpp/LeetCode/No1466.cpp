/*
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). 
Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> ajList(n);
        for(vector<int>& connection : connections){
            ajList[connection[0]].push_back({connection[1], true});
            ajList[connection[1]].push_back({connection[0], false});
        }
        vector<bool> seen(n, false);
        seen[0] = true;
        queue<int> q;
        q.push(0);
        int res = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto [neighbor, org] : ajList[node]){
                if(!seen[neighbor]){
                    res+=org;
                    seen[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    int n;
    vector<vector<int>> connections;

    n = 6;
    connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout << solution.minReorder(n, connections) << endl;

    n = 5;
    connections = {{1,0},{1,2},{3,2},{3,4}};
    cout << solution.minReorder(n, connections) << endl;

    n = 3;
    connections = {{1,0},{2,0}};
    cout << solution.minReorder(n, connections) << endl;

    n = 3;
    connections = {{1,2},{2,0}};
    cout << solution.minReorder(n, connections) << endl;
    return 0;
}