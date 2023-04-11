/*
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). 
An island is a group of 1's connected 4-directionally (horizontal or vertical). 
Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int res = 0;
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                if(grid2[i][j]==1){
                    res+=findSubIslands(grid1, grid2, i, j);
                }
            }
        }
        return res;
    }
private:
    const vector<int> dirs = {1,0,-1,0,1};
    bool findSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y){
        queue<pair<int, int>> q;
        bool find = true;
        q.push({x, y});
        grid2[x][y] = 0;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            if(grid1[p.first][p.second]==0) find = false;
            for(int d=0;d<4;d++){
                int dx = p.first+dirs[d];
                int dy = p.second+dirs[d+1];
                if(dx<0 || dx>=grid2.size()
                || dy<0 || dy>=grid2[0].size()
                || grid2[dx][dy]==0) continue;
                grid2[dx][dy] = 0;
                q.push({dx, dy});
            }
        }
        return find;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> grid1;
    vector<vector<int>> grid2;

    grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
    cout << solution.countSubIslands(grid1, grid2) << endl;

    grid1 = {{1,0,1,0,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1}};
    grid2 = {{0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,0,0,1}};
    cout << solution.countSubIslands(grid1, grid2) << endl;
    return 0;
}