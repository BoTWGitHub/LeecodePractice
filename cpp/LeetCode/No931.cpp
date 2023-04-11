/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> mem(matrix.size(), vector<int>(matrix[0].size(), -1));
        int res = INT_MAX;
        for(int i=0;i<matrix[0].size();i++){
            res = min(res, dp(matrix, 0, i, mem));
        }
        return res;
    }
private:
    int dp(vector<vector<int>>& matrix, int x, int y, vector<vector<int>> &mem){
        if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size()) return INT_MAX;
        if(x==matrix.size()-1) return matrix[x][y];
        if(mem[x][y]!=-1) return mem[x][y];

        int res = matrix[x][y] + min(dp(matrix, x+1, y, mem), min(dp(matrix, x+1, y+1, mem), dp(matrix, x+1, y-1, mem)));
        return mem[x][y] = res;
    }
};

class Solution2 {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int temp = matrix[i-1][j];
                if(j-1>=0) temp = min(temp, matrix[i-1][j-1]);
                if(j+1<matrix[0].size()) temp = min(temp, matrix[i-1][j+1]);
                matrix[i][j]+=temp;
                if(i==matrix.size()-1) res = min(res, matrix[i][j]);
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;

    vector<vector<int>> matrix;

    matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout << solution.minFallingPathSum(matrix) << endl;

    matrix = {{-19,57},{-40,-5}};
    cout << solution.minFallingPathSum(matrix) << endl;

    return 0;
}