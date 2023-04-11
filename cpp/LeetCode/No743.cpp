/*
You are given a network of n nodes, labeled from 1 to n. 
You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi)
, where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. 
Return the minimum time it takes for all the n nodes to receive the signal. 
If it is impossible for all the n nodes to receive the signal, return -1.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
#include "Debug\VectorDebug.h"
#include <algorithm>
using namespace std;

//dijkstra's algorithm
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> ajList(n);
        for(vector<int> t : times) ajList[t[0]-1].push_back({t[1]-1, t[2]});

        vector<int> cost(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        heap.push({0, k-1});
        cost[k-1] = 0;
        
        while(!heap.empty()){
            pair<int, int> node = heap.top();
            heap.pop();
            for(pair<int, int>& path : ajList[node.second]){
                if(node.first+path.second<cost[path.first]){
                    cost[path.first] = node.first+path.second;
                    heap.push({node.first+path.second, path.first});
                }
            }
        }
        int res = *max_element(cost.begin(), cost.end());
        return res==INT_MAX?-1:res;
    }
};

//bellman ford basic
class Solution2 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> ajList(n);
        for(vector<int> t : times) ajList[t[0]-1].push_back({t[1]-1, t[2]});
        
        vector<int> p(n, INT_MAX);
        p[k-1] = 0;
        for(int i=0;i<n;i++){
            vector<int> c = p;
            for(int j=0;j<n;j++){
                if(p[j]==INT_MAX) continue;
                for(pair<int, int>& t : ajList[j]){
                    c[t.first] = min(c[t.first], p[j]+t.second);
                }
            }
            p=c;
        }
        int res = *max_element(p.begin(), p.end());
        return res==INT_MAX?-1:res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> times;
    int n;
    int k;

    times = {{2,1,1},{2,3,1},{3,4,1}};
    n=4;
    k=2;
    cout << solution.networkDelayTime(times, n, k) << endl;

    times = {{1,2,1}};
    n=2;
    k=1;
    cout << solution.networkDelayTime(times, n, k) << endl;

    times = {{1,2,1}};
    n=2;
    k=2;
    cout << solution.networkDelayTime(times, n, k) << endl;

    times = {{1,2,1},{2,3,2},{1,3,4}};
    n=3;
    k=1;
    cout << solution.networkDelayTime(times, n, k) << endl;

    times = {{1,2,1},{2,3,7},{1,3,4},{2,1,2}};
    n=4;
    k=1;
    cout << solution.networkDelayTime(times, n, k) << endl;

    times = {{1,2,1},{2,1,3}};
    n=2;
    k=2;
    cout << solution.networkDelayTime(times, n, k) << endl;

    times = {{1,2,1},{2,3,7},{1,3,4},{2,1,2}};
    n=3;
    k=2;
    cout << solution.networkDelayTime(times, n, k) << endl;
    return 0;
}