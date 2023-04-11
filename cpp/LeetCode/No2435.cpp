/*
You are given a 0-indexed m x n integer matrix grid and an integer k. 
You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.

Return the number of paths where the sum of the elements on the path is divisible by k.
Since the answer may be very large, return it modulo 10^9 + 7.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int mod = pow(10, 9) + 7;
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k, 0)));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0&&j==0){
                    dp[i][j][grid[i][j]%k] = 1;
                }
                else{
                    if(i-1>=0){
                        for(int kk=0;kk<k;kk++){
                            int index = (grid[i][j]+kk)%k;
                            dp[i][j][index]+=dp[i-1][j][kk];
                            dp[i][j][index]%=mod;
                        }
                    }
                    if(j-1>=0){
                        for(int kk=0;kk<k;kk++){
                            int index = (grid[i][j]+kk)%k;
                            dp[i][j][index]+=dp[i][j-1][kk];
                            dp[i][j][index]%=mod;
                        }
                    }
                }
            }
        }
        return dp.back().back()[0];
    }
};

int main(){
    Solution solution;

    vector<vector<int>> grid = {{5,2,4}, {3,0,5}, {0,7,2}};
    int k = 3;
    cout << solution.numberOfPaths(grid, k) << endl;
    return 0;
}
