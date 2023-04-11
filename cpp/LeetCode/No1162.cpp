/*
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land
, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. 
If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) q.push({i, j});
            }
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
                    || dy<0 || dy>=grid[0].size()
                    || grid[dx][dy]==1) continue;
                    grid[dx][dy] = 1;
                    q.push({dx, dy});
                }
            }
        }
        if(res==1) return -1;
        return res-1;
    }
private:
    const vector<int> dirs = {1,0,-1,0,1};
};

int main(void){
    Solution solution;
    vector<vector<int>> grid;

    grid = {{1,0,1},{0,0,0},{1,0,1}};
    cout << solution.maxDistance(grid) << endl;

    grid = {{1,0,0},{0,0,0},{0,0,0}};
    cout << solution.maxDistance(grid) << endl;
    return 0;
}