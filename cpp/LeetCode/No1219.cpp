/*
In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    res = max(res, backtrack(grid, i, j));
                }
            }
        }
        return res;
    }
private:
    int backtrack(vector<vector<int>>& grid, int x, int y){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==0) return 0;
        int temp = grid[x][y];
        grid[x][y] = 0;
        int res = max(max(backtrack(grid, x+1, y), backtrack(grid, x, y+1)), max(backtrack(grid, x-1, y), backtrack(grid, x, y-1)))+temp;
        grid[x][y] = temp;
        return res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> grid;

    grid = {{0,6,0},{5,8,7},{0,9,0}};
    cout << solution.getMaximumGold(grid) << endl;

    grid = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
    cout << solution.getMaximumGold(grid) << endl;

    grid = {{1,0,7,0,0,0},{2,0,6,0,1,0},{3,5,6,7,4,2},{4,3,1,0,2,0},{3,0,5,0,20,0}};
    cout << solution.getMaximumGold(grid) << endl;
    return 0;
}