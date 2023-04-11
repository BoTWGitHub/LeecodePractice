/*
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. 
You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). 
You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. 
Since the answer can be very large, return it modulo 10^9 + 7.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> mem(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return dp(m, n, maxMove, startRow, startColumn, mem);
    }
private:
    const int mod = 1e9+7;
    const vector<int> dirs = {1,0,-1,0,1};
    int dp(int& m, int& n, int maxMove, int x, int y, vector<vector<vector<int>>>& mem){
        if(x<0 || x>=m || y<0 || y>=n) return 1;
        if(maxMove==0) return 0;
        if(mem[x][y][maxMove]!=-1) return mem[x][y][maxMove];

        int res = 0;
        for(int i=0;i<4;i++){
            int dx = x+dirs[i];
            int dy = y+dirs[i+1];
            res = (res + dp(m, n, maxMove-1, dx, dy, mem))%mod;
        }
        return mem[x][y][maxMove] = res;
    }
};

int main(void){
    Solution solution;
    int m;
    int n;
    int maxMove;
    int startRow;
    int startColumn;

    m = 2;
    n = 2;
    maxMove = 2;
    startRow = 0;
    startColumn = 0;
    cout << solution.findPaths(m, n, maxMove, startRow, startColumn) << endl;

    m = 1;
    n = 3;
    maxMove = 3;
    startRow = 0;
    startColumn = 1;
    cout << solution.findPaths(m, n, maxMove, startRow, startColumn) << endl;
    return 0;
}