/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> mem(matrix.size(), vector<int>(matrix[0].size(), -1));
        int res = 1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                res = max(res, dp(matrix, {i, j}, mem));
            }
        }
        return res;
    }
private:
    const vector<int> dirs = {1,0,-1,0,1};
    int dp(vector<vector<int>>& matrix, pair<int, int> pos, vector<vector<int>>& mem){
        if(mem[pos.first][pos.second]!=-1) return mem[pos.first][pos.second];

        int res = 1;
        for(int i=0;i<4;i++){
            int dx = pos.first+dirs[i];
            int dy = pos.second+dirs[i+1];
            if(dx<0 || dx>=matrix.size() || dy<0 || dy>=matrix[0].size()) continue;
            if(matrix[dx][dy]>matrix[pos.first][pos.second]){
                res = max(res, dp(matrix, {dx, dy}, mem)+1);
            }
        }
        return mem[pos.first][pos.second] = res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> matrix;

    matrix = {{9,9,4},{6,6,8},{2,1,1}};
    cout << solution.longestIncreasingPath(matrix) << endl;

    matrix = {{3,4,5},{3,2,6},{2,2,1}};
    cout << solution.longestIncreasingPath(matrix) << endl;

    matrix = {{1}};
    cout << solution.longestIncreasingPath(matrix) << endl;
    return 0;
}