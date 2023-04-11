/*
Given a 2D grid consists of 0s (land) and 1s (water).
An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(row==1 || col==1) return 0;
        int res = 0;
        for(int i=1;i<row-1;i++){
            for(int j=1;j<col-1;j++){
                if(grid[i][j]==0){
                    grid[i][j]=1;
                    res+=bfs(grid, {i, j}, row, col);
                }
            }
        }
        return res;
    }
private:
    const vector<int> dirs = {1,0,-1,0,1};
    bool bfs(vector<vector<int>>& grid, pair<int, int> pos, int row, int col){
        bool res = true;
        queue<pair<int, int>> q;
        q.push(pos);
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            if(res && (p.first==0 || p.first==row-1 || p.second==0 || p.second==col-1)) res = false;
            for(int i=0;i<4;i++){
                int nx = p.first+dirs[i];
                int ny = p.second+dirs[i+1];
                if(nx<0 || nx>=row || ny<0 || ny>=col || grid[nx][ny]==1) continue;
                grid[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
        return res;
    }
};

int main(void){

    return 0;
}