/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. 
You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain
, and the rain water can flow to neighboring cells directly north, south, east, and west 
if the neighboring cell's height is less than or equal to the current cell's height. 
Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes 
that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
*/
#include <iostream>
#include <vector>
#include <queue>
#include "Debug\VectorDebug.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> waters(row, vector<int>(col, 0));
        queue<pair<int, int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 || j==0 || i==row-1 || j==col-1){
                    q.push({i, j});
                    if(i==0 || j==0){
                        waters[i][j]|=1;
                    }
                    if(i==row-1 || j==col-1){
                        waters[i][j]|=2;
                    }
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                pair<int, int> p = q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int dx=p.first+dirs[d];
                    int dy=p.second+dirs[d+1];
                    if(dx<0 || dx>=row
                    || dy<0 || dy>=col
                    || waters[dx][dy]==waters[p.first][p.second] 
                    || heights[dx][dy]<heights[p.first][p.second]) continue;
                    waters[dx][dy]|=waters[p.first][p.second];
                    q.push({dx, dy});
                }
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(waters[i][j]==3){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
private:
    const vector<int> dirs = {1,0,-1,0,1};
};

int main(void){
    Solution solution;
    vector<vector<int>> heights;
    vector<vector<int>> res;

    heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    res = solution.pacificAtlantic(heights);
    print2DVector(res);

    heights = {{1}};
    res = solution.pacificAtlantic(heights);
    print2DVector(res);
    return 0;
}