/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
*/
#include <iostream>
#include <cmath>
#include "Debug\VectorDebug.h"

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        vector<int> dp(matrix[0].size(), 0);
        for(int i=0;i<matrix.size();i++){
            vector<int> temp(matrix[0].size(), 0);
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    if(i>0 && j>0){
                        temp[j] = min(min(dp[j], dp[j-1]), temp[j-1])+1;
                    }
                    else{
                        temp[j] = 1;
                    }
                    res = max(res, temp[j]);
                }
                else{
                    temp[j] = 0;
                }
            }
            dp = temp;
        }
        return res*res;
    }
};

int main(void){
    Solution solution;

    vector<vector<char>> matrix = {{'1','1','1','1','0'},{'1','1','1','1','0'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'0','0','1','1','1'}};
    cout << solution.maximalSquare(matrix) << endl;
    return 0;
}