/*
Given an m x n binary matrix mat, return the length of the longest line of consecutive one in the matrix.

The line could be horizontal, vertical, diagonal, or anti-diagonal.
*/
#include <iostream>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int res = 0;
        vector<vector<int>> dp(mat[0].size(), vector<int>(4, 0));
        for(int i=0;i<mat.size();i++){
            vector<vector<int>> temp(mat[0].size(), vector<int>(4, 0));
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    for(int d=0;d<4;d++){
                        int dx = i+dirs[d][0];
                        int dy = j+dirs[d][1];
                        if(dx<0 || dx>=mat.size() || dy<0 || dy>=mat[0].size()){
                            temp[j][d] = 1;
                        }
                        else{
                            if(d==0){
                                temp[j][d] = temp[dy][d]+1;
                            }
                            else{
                                temp[j][d] = dp[dy][d]+1;
                            }
                        }
                        res = max(res, temp[j][d]);
                    }
                }
            }
            dp = temp;
        }
        return res;
    }
private:
    const vector<vector<int>> dirs = {{0,-1},{-1,-1},{-1,0},{-1,1}};
};

int main(void){
    Solution solution;
    vector<vector<int>> mat;

    mat = {{0,1,1,0},{0,1,1,0},{0,0,0,1}};
    cout << solution.longestLine(mat) << endl;

    mat = {{1,1,1,1},{0,1,1,0},{0,0,0,1}};
    cout << solution.longestLine(mat) << endl;
    return 0;
}