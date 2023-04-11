/*
Given an m x n matrix grid where each cell is either a wall 'W', an enemy 'E' or empty '0'
, return the maximum enemies you can kill using one bomb. 
You can only place the bomb in an empty cell.

The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since it is too strong to be destroyed.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        vector<vector<pair<int, int>>> mem(grid.size(), vector<pair<int, int>>(grid[0].size(), {-1, -1}));
        return dp(grid, 0, 0, mem);
    }
private:
    int dp(vector<vector<char>>& grid, int x, int y, vector<vector<pair<int, int>>>& mem){
        if(y==grid[0].size()){
            y = 0;
            x++;
            if(x==grid.size()) return 0;
        }
        if(grid[x][y]!='0') return dp(grid, x, y+1, mem);
        
        int rowHit = mem[x][y].first;
        int colHit = mem[x][y].second;
        if(rowHit==-1){
            rowHit = 0;
            int xHigh = x;
            while(xHigh<grid.size()){
                if(grid[xHigh][y]=='W') break;
                else if(grid[xHigh][y]=='E') rowHit++;
                xHigh++;
            }
            int xLow = x;
            while(xLow>=0){
                if(grid[xLow][y]=='W') break;
                else if(grid[xLow][y]=='E') rowHit++;
                xLow--;
            }
            for(int i=xLow+1;i<xHigh;i++) mem[i][y].first = rowHit;
        }
        if(colHit==-1){
            colHit = 0;
            int yHigh = y;
            while(yHigh<grid[0].size()){
                if(grid[x][yHigh]=='W') break;
                else if(grid[x][yHigh]=='E') colHit++;
                yHigh++;
            }
            int yLow = y;
            while(yLow>=0){
                if(grid[x][yLow]=='W') break;
                else if(grid[x][yLow]=='E') colHit++;
                yLow--;
            }
            for(int i=yLow+1;i<yHigh;i++) mem[x][i].second = colHit;
        }
        return max(rowHit+colHit, dp(grid, x, y+1, mem));
    }
};

int main(void){
    Solution solution;
    vector<vector<char>> grid;

    grid = {{'0','E','0','0'},{'E','0','W','E'},{'0','E','0','0'}};
    cout << solution.maxKilledEnemies(grid) << endl;
    
    grid = {{'W','W','W'},{'0','0','0'},{'E','E','E'}};
    cout << solution.maxKilledEnemies(grid) << endl;
    return 0;
}