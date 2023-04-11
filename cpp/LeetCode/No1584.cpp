/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|
, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. 
All points are connected if there is exactly one simple path between any two points.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "Debug\UnionFind.h"
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.size()<=1) return 0;
        vector<bool> seen(points.size(), false);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;
        seen[0] = true;
        for(int i=1;i<points.size();i++){
            int dist = abs(points[0][0]-points[i][0]) + abs(points[0][1]-points[i][1]);
            heap.push({dist, {0, i}});
        }
        int count = points.size()-1;
        int res = 0;
        while(!heap.empty() && count>0){
            pair<int, pair<int, int>> p = heap.top();
            heap.pop();
            if(!seen[p.second.second]){
                seen[p.second.second] = true;
                res+=p.first;
                for(int i=0;i<points.size();i++){
                    if(!seen[i]){
                        int dist = abs(points[p.second.second][0]-points[i][0]) + abs(points[p.second.second][1]-points[i][1]);
                        heap.push({dist, {p.second.second, i}});
                    }
                }
                count--;
            }
            
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> points;

    points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << solution.minCostConnectPoints(points) << endl;

    points = {{3,12},{-2,5},{-4,1}};
    cout << solution.minCostConnectPoints(points) << endl;
    return 0;
}