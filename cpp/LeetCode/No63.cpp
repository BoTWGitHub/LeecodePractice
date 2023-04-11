/*
You are given an m x n integer array grid. 
There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). 
The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. 
A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 10^9.
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> mem(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return dp(obstacleGrid, 0, 0, mem);
    }
private:
    int mod = 2*pow(10,9);
    int dp(vector<vector<int>>& obstacleGrid, int x, int y, vector<vector<int>>& mem){
        if(x<0 || x>=obstacleGrid.size() || y<0 || y>=obstacleGrid[0].size() || obstacleGrid[x][y] == 1) return 0;
        if(x==obstacleGrid.size()-1 && y==obstacleGrid[0].size()-1) return 1;
        if(mem[x][y]!=-1) return mem[x][y];

        int res = dp(obstacleGrid, x+1, y, mem) + dp(obstacleGrid, x, y+1, mem);
        res%=mod;
        return mem[x][y] = res;
    }
};

int main(void){
    Solution solution;

    vector<vector<int>> obstacleGrid;

    obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;

    obstacleGrid = {{0,1},{0,0}};
    cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}