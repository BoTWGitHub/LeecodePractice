/*
Given two sparse matrices mat1 of size m x k and mat2 of size k x n
, return the result of mat1 x mat2. You may assume that multiplication is always possible.
*/
#include <iostream>
#include "Debug\VectorDebug.h"

class Solution {
public:
    std::vector<std::vector<int>> multiply(std::vector<std::vector<int>>& mat1, std::vector<std::vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat1[0].size();
        int n = mat2[0].size();
        std::vector<std::vector<int>> res(m, std::vector<int>(n, 0));
        std::vector<std::vector<std::pair<int, int>>> l1(m);
        std::vector<std::vector<std::pair<int, int>>> l2(k);
        for(int i=0;i<m;i++){
            for(int j=0;j<k;j++){
                if(mat1[i][j]!=0){
                    l1[i].push_back({mat1[i][j], j});
                }
            }
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                if(mat2[i][j]!=0){
                    l2[i].push_back({mat2[i][j], j});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(auto [val1, col1] : l1[i]){
                for(auto [val2, col2] : l2[col1]){
                    res[i][col2]+=val1*val2;
                }
            }
        }
        return res;
    }
};

int main(void){
    Solution solution;
    std::vector<std::vector<int>> mat1;
    std::vector<std::vector<int>> mat2;
    std::vector<std::vector<int>> res;

    mat1 = {{1,0,0},{-1,0,3}};
    mat2 = {{7,0,0},{0,0,0},{0,0,1}};
    res = solution.multiply(mat1, mat2);
    print2DVector(res);

    mat1 = {{0}};
    mat2 = {{0}};
    res = solution.multiply(mat1, mat2);
    print2DVector(res);
    return 0;
}