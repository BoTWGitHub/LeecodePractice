/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include "Debug\VectorDebug.h"

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int first = cost[0];
        int second = cost[1];
        int third;
        for(int i=2;i<n;i++){
            third = min(first, second) + cost[i];
            first = second;
            second = third;
        }
        return min(first, second);
    }
};

int main(){
    Solution solution;

    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout << solution.minCostClimbingStairs(cost) << endl;
    return 0;
}
