/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections 
forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. 
Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ajList(n);
        for(vector<int> con : connections){
            ajList[con[0]].push_back(con[1]);
            ajList[con[1]].push_back(con[0]);
        }
        int timestamp = 0;
        vector<vector<int>> res;
        vector<int> time(n, -1);
        for(int i=0;i<n;i++){
            if(time[i]==-1){
                time[i]=timestamp++;
                dfs(ajList, res, i, -1, timestamp, time);
            }
        }
        return res;
    }
private:
    int dfs(vector<vector<int>> &ajList, vector<vector<int>> &res, int node, int last, int &timestamp, vector<int> &time){
        int minTime = time[node];
        for(int n : ajList[node]){
            if(n==last) continue;
            if(time[n]==-1){
                time[n]=timestamp++;
                int ret = dfs(ajList, res, n, node, timestamp, time);
                minTime = min(minTime, ret);
                if(ret>time[node]) res.push_back({node, n});
            }
            else{
                minTime = min(minTime, time[n]);
            }
        }
        return minTime;
    }
};

int main(void){
    Solution solution;
    int n;
    vector<vector<int>> connections;
    vector<vector<int>> res;

    n = 4;
    connections = {{0,1},{1,2},{2,0},{1,3}};
    res = solution.criticalConnections(n, connections);
    print2DVector(res);

    n = 2;
    connections = {{0,1}};
    res = solution.criticalConnections(n, connections);
    print2DVector(res);
    return 0;
}