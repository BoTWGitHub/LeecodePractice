/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> mem(grid.size(), vector<int>(grid[0].size(), -1));
        return dp(grid, 0, 0, mem);
    }
private:
    int dp(vector<vector<int>>& grid, int x, int y, vector<vector<int>> &mem){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()) return INT_MAX;
        if(x==grid.size()-1 && y==grid[0].size()-1) return grid[x][y];
        if(mem[x][y]!=-1) return mem[x][y];

        int res = grid[x][y] + min(dp(grid, x+1, y, mem), dp(grid, x, y+1, mem));
        return mem[x][y] = res;
    }
};

int main(void){
    Solution solution;

    vector<vector<int>> grid;

    grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << solution.minPathSum(grid) << endl;

    grid = {{1,2,3},{4,5,6}};
    cout << solution.minPathSum(grid) << endl;

    return 0;
}