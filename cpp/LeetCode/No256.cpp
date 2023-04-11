/*
There is a row of n houses, where each house can be painted one of three colors: red, blue, or green. 
The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.

For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost of painting house 1 with color green, and so on...
Return the minimum cost to paint all houses.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> mem(costs.size(), vector<int>(3, -1));
        return dp(costs, 0, -1, mem);
    }
private:
    int dp(vector<vector<int>>& costs, int index, int last, vector<vector<int>> &mem){
        if(index==costs.size()) return 0;
        if(last!=-1 && mem[index][last]!=-1) return mem[index][last];

        int res = INT_MAX;
        for(int i=0;i<3;i++){
            if(i==last) continue;
            res = min(res, dp(costs, index+1, i, mem)+costs[index][i]);
        }
        if(last!=-1) mem[index][last] = res;
        return res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> costs;

    costs = {{17,2,17},{16,16,5},{14,3,19}};
    cout << solution.minCost(costs) << endl;

    costs = {{7,6,2}};
    cout << solution.minCost(costs) << endl;

    return 0;
}