/*
On a campus represented on the X-Y plane, there are n workers and m bikes, with n <= m.

You are given an array workers of length n where workers[i] = [xi, yi] is the position of the ith worker. 
You are also given an array bikes of length m where bikes[j] = [xj, yj] is the position of the jth bike. 
All the given positions are unique.

Assign a bike to each worker. 
Among the available bikes and workers, we choose the (workeri, bikej) pair with the shortest Manhattan distance between each other 
and assign the bike to that worker.

If there are multiple (workeri, bikej) pairs with the same shortest Manhattan distance
, we choose the pair with the smallest worker index. 
If there are multiple ways to do that
, we choose the pair with the smallest bike index. 
Repeat this process until there are no available workers.

Return an array answer of length n, where answer[i] is the index (0-indexed) of the bike that the ith worker is assigned to.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.
*/
#include <iostream>
#include <vector>
#include "Debug\VectorDebug.h"
#include <map>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<int> res(workers.size(), -1);
        vector<tuple<int, int, int>> pairs;
        vector<bool> assigned(bikes.size(), false);
        for(int i=0;i<workers.size();i++){
            for(int j=0;j<bikes.size();j++){
                int dis = abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
                pairs.push_back({dis, i, j});
            }
        }
        sort(pairs.begin(), pairs.end());
        int count = bikes.size();
        for(auto& [dis, worker, bike] : pairs){
            if(res[worker]==-1 && !assigned[bike]){
                res[worker] = bike;
                assigned[bike] = true;
                count--;
                if(count==0) return res;
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> workers;
    vector<vector<int>> bikes;
    vector<int> res;

    workers = {{0,0},{2,1}};
    bikes = {{1,2},{3,3}};
    res = solution.assignBikes(workers, bikes);
    printVector(res);

    workers = {{0,0},{1,1},{2,0}};
    bikes = {{1,0},{2,2},{2,1}};
    res = solution.assignBikes(workers, bikes);
    printVector(res);

    workers = {{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0}};
    bikes = {{0,999},{1,999},{2,999},{3,999},{4,999},{5,999},{6,999},{7,999},{8,999}};
    res = solution.assignBikes(workers, bikes);
    printVector(res);
    return 0;
}