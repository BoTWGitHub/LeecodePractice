/*
There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n)
, some houses that have been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color.

For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].
Given an array houses, an m x n matrix cost and an integer target where:

houses[i]: is the color of the house i, and 0 if the house is not painted yet.
cost[i][j]: is the cost of paint the house i with the color j + 1.
Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. 
If it is not possible, return -1.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> mem(m, vector<vector<int>>(n, vector<int>(target+1, -1)));
        int res = dp(houses, cost, target, 0, -1, 0, mem);
        return res!=INT_MAX?res:-1;
    }
private:
    int dp(vector<int>& houses, vector<vector<int>>& cost, int target, int index, int last, int group, vector<vector<vector<int>>> &mem){
        if(group>target) return INT_MAX;
        if(index==houses.size()) return group==target?0:INT_MAX;
        if(last!=-1 && mem[index][last][group]!=-1) return mem[index][last][group];

        int res = INT_MAX;
        if(houses[index]==0){ //need to paint
            for(int i=0;i<cost[0].size();i++){
                int temp = dp(houses, cost, target, index+1, i, group+(i!=last), mem);
                if(temp!=INT_MAX) temp+=cost[index][i];
                res = min(res, temp);
            }
        }
        else{ //don't need to paint
            res = min(res, dp(houses, cost, target, index+1, houses[index]-1, group+(houses[index]-1!=last), mem));
        }

        if(last!=-1) mem[index][last][group] = res;
        return res;
    }
};

int main(void){
    Solution solution;
    vector<int> houses;
    vector<vector<int>> cost;
    int m, n, target;

    houses = {0,0,0,0,0};
    cost = {{1,10},{10,1},{10,1},{1,10},{5,1}};
    m = 5;
    n = 2;
    target = 3;
    cout << solution.minCost(houses, cost, m, n, target) << endl;

    houses = {0,2,1,2,0};
    cost = {{1,10},{10,1},{10,1},{1,10},{5,1}};
    m = 5;
    n = 2;
    target = 3;
    cout << solution.minCost(houses, cost, m, n, target) << endl;

    houses = {3,1,2,3};
    cost = {{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1}};
    m = 4;
    n = 3;
    target = 3;
    cout << solution.minCost(houses, cost, m, n, target) << endl;

    return 0;
}