/*
You are given a 0-indexed m x n binary matrix grid. 
You can move from a cell (row, col) to any of the cells (row + 1, col) or (row, col + 1).

Return true if there is a path from (0, 0) to (m - 1, n - 1) that visits an equal number of 0's and 1's. 
Otherwise return false.
*/
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool isThereAPath(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if((m+n-1)%2==1) return false;
        std::vector<std::vector<std::unordered_set<int>>> gridSum(m, std::vector<std::unordered_set<int>>(n));
        gridSum[0][0].insert(grid[0][0]);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j-1>=0){
                    for(int num : gridSum[i][j-1]){
                        gridSum[i][j].insert(num+grid[i][j]);
                    }
                }
                if(i-1>=0){
                    for(int num : gridSum[i-1][j]){
                        gridSum[i][j].insert(num+grid[i][j]);
                    }
                }
            }
        }
        return gridSum.back().back().count((m+n-1)/2);
    }
};

int main(void){
    Solution solution;
    std::vector<std::vector<int>> grid;

    grid = {{0,1,0,0},{0,1,0,0},{1,0,1,0}};
    std::cout << solution.isThereAPath(grid) << std::endl;

    grid = {{1,1,0},{0,0,1},{1,0,0}};
    std::cout << solution.isThereAPath(grid) << std::endl;
    return 0;
}