/*
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. 
There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        bool found = false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q = findCoast(grid, i, j);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i=0;i<size;i++){
                pair<int, int> p = q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int dx = p.first+dirs[d];
                    int dy = p.second+dirs[d+1];
                    if(dx<0 || dx>=grid.size()
                    || dy<0 || dy>=grid[0].size()) continue;
                    if(grid[dx][dy]==1) return res-1;
                    if(grid[dx][dy]==0){
                        q.push({dx, dy});
                        grid[dx][dy] = -1;
                    }
                }
            }
        }
        return -1;
    }
private:
    const vector<int> dirs = {1,0,-1,0,1};
    queue<pair<int, int>> findCoast(vector<vector<int>>& grid, int x, int y){
        queue<pair<int, int>> q;
        queue<pair<int, int>> res;
        q.push({x, y});
        grid[x][y] = -1;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            bool foundWater = false;
            for(int d=0;d<4;d++){
                int dx = p.first+dirs[d];
                int dy = p.second+dirs[d+1];
                if(dx<0 || dx>=grid.size()
                || dy<0 || dy>=grid[0].size()) continue;
                if(grid[dx][dy]==0) foundWater = true;
                if(grid[dx][dy]==1){
                    q.push({dx, dy});
                    grid[dx][dy]=-1;
                }
            }
            if(foundWater) res.push({p.first, p.second});
        }
        return res;
    }
};

int main(void){
    Solution solution;
    vector<vector<int>> grid;

    grid = {{0,1},{1,0}};
    cout << solution.shortestBridge(grid) << endl;

    grid = {{0,1,0},{0,0,0},{0,0,1}};
    cout << solution.shortestBridge(grid) << endl;
    return 0;
}