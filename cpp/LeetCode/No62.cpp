/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^9.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(n+1, vector<int>(m+1, -1));
        return dp(m, n, 0, 0, mem);
    }
private:
    int dp(int m, int n, int x, int y, vector<vector<int>> &mem){
        if(y>=m) return 0;
        if(x>=n) return 0;
        if(x==n-1 && y==m-1) return 1;
        if(mem[x][y]!=-1) return mem[x][y];

        int res = dp(m, n, x+1, y, mem) + dp(m, n, x, y+1, mem);
        return mem[x][y] = res;
    }
};

int main(void){
    Solution solution;

    int m, n;

    m = 3;
    n = 7;
    cout << solution.uniquePaths(m, n) << endl;

    m = 3;
    n = 2;
    cout << solution.uniquePaths(m, n) << endl;

    return 0;
}